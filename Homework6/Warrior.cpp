//Author : Jaeha Huh
//File name : Warrior.cpp


#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
using namespace std;

namespace WarriorCraft {

	//Warrior class implementation***
	ostream& operator<<(ostream& os, const Warrior& rhs) {
		os << "    " << rhs.name << ": " << rhs.strength << endl;
		return os;
	}

	Warrior::Warrior(const string& name, double strength) :
		name(name), strength(strength), boss(nullptr) {}

	string Warrior::getName() const { return name; }

	double Warrior::getStrength() const { return strength; }

	bool Warrior::hireStatus() const { return hired; }

	bool Warrior::lifeStatus() const { return alive; }

	void Warrior::setStrength(double inputStrength) { strength = inputStrength; }

	void Warrior::setHire(bool status) { hired = status; }

	void Warrior::setAlive(bool status) { alive = status; }

	void Warrior::setBoss(Noble* aNoble) { boss = aNoble; }

	void Warrior::runaway() {
		if (alive == true && boss != nullptr) {
			cout << name << " flees in terror, abandoning his lord, " << boss->getName() << endl;
			boss->findAndRemoveWarrior(*this);
			boss = nullptr;
			hired = false;
		}
	}
}


