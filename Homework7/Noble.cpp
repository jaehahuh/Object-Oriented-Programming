//Author: Jaeha Huh
//Name of File: Noble.cpp

#include "Protector.h"
#include <iostream>
using namespace std;

namespace WarriorCraft {

	Noble::Noble(const string& name) : name(name), alive(true) {}
	const string& Noble::getName() const { return name; }
	bool Noble::lifeStatus() const { return alive; }
	void Noble::setAlive(bool status) { alive = status; }
	void Noble::battle(Noble& aNoble) {
		if (this == &aNoble) {
			cout << "I cannot fight myself" << endl;
			return;
		}
		cout << name << " battles " << aNoble.getName() << endl;

		if (alive == false && aNoble.lifeStatus() == false) {
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
		else if (alive == false && aNoble.lifeStatus() == true) {
			cout << "He is dead, " << aNoble.getName() << endl;
		}
		else if (alive == true && aNoble.lifeStatus() == false) {
			cout << "He is dead, " << name << endl;
		}
		else { //if both of them are alive
			defend();
			aNoble.defend();
			float ratio = getStrength() / aNoble.getStrength();
			//compare their strength using a ratio
			if (ratio == 1) { // both are equally strong
				setStrength(1);
				aNoble.setStrength(1);
				setAlive(false);
				aNoble.setAlive(false);
				cout << "Mutual Annihilation: " << name
					<< " and " << aNoble.getName() <<
					" die at each other's hands." << endl;
			}
			else if (ratio < 1) { //if self is weaker
				setStrength(1);
				aNoble.setStrength(ratio);
				setAlive(false);
				cout << aNoble.getName() << " defeats " << name << endl;
			}
			else { //if enermy is weaker 
				aNoble.setStrength(1);
				setStrength(1 / ratio);
				aNoble.setAlive(false);
				cout << name << " defeats " << aNoble.getName() << endl;
			}
		}
	}


	PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, float strength)
		: Noble(name), strength(strength) {}
	float PersonWithStrengthToFight::getStrength() const { return strength; }
	void PersonWithStrengthToFight::setStrength(float ratio) { strength *= (1 - ratio); }
	void PersonWithStrengthToFight::setAlive(bool status) { Noble::setAlive(status); }//no need to override



	Lord::Lord(const string& name) : Noble(name) {}
	float Lord::getStrength() const { //total strength of a lord's army
		float totalStrength = 0;
		for (const Protector* aProtector : army) {
			totalStrength += aProtector->getStrength();
		}
		return totalStrength;
	}
	void Lord::setStrength(float ratio) {
		for (Protector* aProtector : army) {
			aProtector->setStrength(aProtector->getStrength() * (1 - ratio));
		}
	}
	void Lord::setAlive(bool status) {
		//set lord's and protector's alive status
		Noble::setAlive(status);
		for (Protector* aProtector : army) {
			aProtector->setAlive(status);
		}
	}
	void Lord::hires(Protector& aProtector) {
		if (ifAProtectorInArmy(aProtector) == true) {
			cout << "Error: Protector is already in the army" << endl;
		}
		else if (aProtector.lifeStatus() == false) {
			cout << "Error: Protector is dead" << endl;
		}
		else if (aProtector.hireStatus() == true) {
			cout << "Error: Protector currently has a job" << endl;
		}
		else if (lifeStatus() == false) {
			cout << "Error: Lord is dead" << endl;
		}
		else {
			army.push_back(&aProtector);
			aProtector.setHire(true);
			aProtector.setBoss(this);
		}
	}
	void Lord::fires(Protector& aProtector) {
		if (lifeStatus() == false) {
			cout << "Dead lord cannot fire protector";
		}
		else if (ifAProtectorInArmy(aProtector) == false) {
			cout << "Protector is not in the army";
		}
		else {
			cout << "You don't work for me anymore, " << aProtector.getName()
				<< "! -- " << getName() << endl;
			for (size_t i = 0; i < army.size(); ++i) {
				if (army[i] == &aProtector) {
					findAndRemoveProtector(*army[i]);
				}
			}
			aProtector.setHire(false);
			aProtector.setBoss(nullptr);
		}
	}
	void Lord::defend() const {
		for (Protector* aProtector : army) {
			aProtector->defend();
		}
	}
	void Lord::findAndRemoveProtector(const Protector& aProtector) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &aProtector) {
				Protector* temp = nullptr;
				army[i] = nullptr;
				for (size_t j = i; j < army.size() - 1; ++j) {
					temp = army[j];
					army[j] = army[j + 1];
					army[j + 1] = temp;
				}
			}
		}
		army.pop_back();
	}
	bool Lord::ifAProtectorInArmy(const Protector& aProtector) const {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &aProtector) {
				return true;
			}
		}
		return false;
	}

}