//Author: Jaeha Huh
//Name of File: Protector.cpp

#include "Protector.h"
#include <iostream>

using namespace std;

namespace WarriorCraft {
	
	Protector::Protector(const string& name, float strength) :
		name(name), strength(strength), alive(true), hired(false), boss(nullptr) {}
	void Protector::defend() const {
		cout << name <<
			" says: Take that in the name of my lord, " << boss->getName() << endl;
	}
	const string& Protector::getName() const { return name; }
	float Protector::getStrength() const { return strength; }
	bool Protector::hireStatus() const { return hired; }
	bool Protector::lifeStatus() const { return alive; }
	void Protector::setStrength(float inputStrength) { strength = inputStrength; }
	void Protector::setHire(bool status) { hired = status; }
	void Protector::setAlive(bool status) { alive = status; }
	void Protector::setBoss(Lord* aLord) { boss = aLord; }
	void Protector::runaway() {
		if (alive == true && boss != nullptr) {
			cout << name << " flees in terror, abandoning his lord, "
				<< boss->getName() << endl;
			boss->findAndRemoveProtector(*this);
			boss = nullptr;
			hired = false;
		}
	}


	Wizard::Wizard(const string& name, float strength) : Protector(name, strength) {}
	void Wizard::defend() const { cout << "POOF!" << endl; }
	

	Warrior::Warrior(const string& name, float strength) : Protector(name, strength) {}

	Archer::Archer(const string& name, float strength) : Warrior(name, strength) {}
	void Archer::defend() const {
		cout << "TWANG! ";
		Protector::defend();
	}
	
	Swordsman::Swordsman(const string& name, float strength) : Warrior(name, strength) {}
	void Swordsman::defend() const {
		cout << "CLANG! ";
		Protector::defend();
	}
	
}