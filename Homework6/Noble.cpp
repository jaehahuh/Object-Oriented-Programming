//Author : Jaeha Huh
//File name : Noble.cpp

#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

namespace WarriorCraft {

	ostream& operator<<(ostream& os, const Noble& rhs) {
		os << rhs.name << " has an army of " << rhs.army.size() << endl;
		for (const Warrior* aWarrior : rhs.army) {
			os << *aWarrior;
		}
		return os;
	}

	Noble::Noble(const string& name) : name(name) {}

	Noble:: ~Noble() {
		while (army.size() != 0) {
			army.pop_back();
		}
	}

	void Noble::hire(Warrior& warrior) {
		if (checkArmy(warrior) == true) {
			cout << "Warrior is already in the army" << endl;
		}
		else if (warrior.lifeStatus() == false) {
			cout << "Warrior is dead" << endl;
		}
		else if (warrior.hireStatus() == true) {
			cout << "Warrior currently has a job" << endl;
		}
		else if (lifeStatus() == false) {
			cout << "Noble is dead already" << endl;
		}
		else {
			Warrior* warPtr = &warrior;
			army.push_back(warPtr);
			warrior.setHire(true);
			warrior.setBoss(this);
		}
	}

	void Noble::fire(Warrior& warrior) {
		if (alive == true) {
			cout << "Dead noble cannot fire warrior";
		}
		else if (checkArmy(warrior) == false) {
			cout << "Warrior is not in the army";
		}
		else {
			cout << "You don't work for me anymore, " << warrior.getName() << "! -- " << name << endl;
			findAndRemoveWarrior(warrior);
			warrior.setHire(false);
			warrior.setBoss(nullptr);
		}
	}

	void Noble::battle(Noble& opponent) {
		cout << name << " battles " << opponent.getName() << endl;

		if (alive == true && opponent.lifeStatus() == false) {
			cout << "He is dead, " << name << endl;
		}

		else if (alive == false && opponent.lifeStatus() == true) {
			cout << "He is dead, " << opponent.getName() << endl;
		}

		else if (alive == false && opponent.lifeStatus() == false) {
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
		//if both of them still alive
		else {
			double selfStrength = getArmyStr();
			double enermyStrength = opponent.getArmyStr();

			if (selfStrength == enermyStrength) {
				adjustNobleAndArmy(0);
				opponent.adjustNobleAndArmy(0);
				cout << "Mutual Annihilation: " << name << " and "
					<< opponent.getName() << " die at each other's hands." << endl;
			}
			else { 
				double weakerStrength = min(selfStrength, enermyStrength);

				if (weakerStrength == selfStrength && weakerStrength != enermyStrength) {
					//if self is weaker
					opponent.adjustNobleAndArmy(0);
					cout << opponent.getName() << " defeats " << name << endl;
					adjustNobleAndArmy(selfStrength / enermyStrength);
				}
				if (weakerStrength == enermyStrength && weakerStrength != selfStrength) {
					//if enermy is weaker
					opponent.adjustNobleAndArmy(0);
					cout << name << " defeats " << opponent.getName() << endl;
					adjustNobleAndArmy(enermyStrength / selfStrength);
				}
			}
		}
	}


	void Noble::adjustNobleAndArmy(double ratio) {
		if (ratio == 0) {
			alive = false;
			for (Warrior* aWarrior : army) {
				aWarrior->setStrength(0);
				aWarrior->setAlive(false);
			}
		}
		else {
			for (Warrior* aWarrior : army) {
				aWarrior->setStrength(aWarrior->getStrength() * (1 - ratio));
			}
		}
	}

	//get total army strength
	double Noble::getArmyStr() const { 
		double totalStrength = 0;
		for (const Warrior* warrior : army) {
			if (warrior != nullptr) {
				totalStrength += warrior->getStrength();
			}
		}
		return totalStrength;
	}
	


	bool Noble::checkArmy(const Warrior& warrior) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &warrior) {
				return true;
			}
		}
		return false;
	}

	void Noble::findAndRemoveWarrior(const Warrior& warrior) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &warrior) {
				Warrior* temp = nullptr;
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

	bool Noble::lifeStatus() const { return alive; }

	string Noble::getName() const { return name; }

}
