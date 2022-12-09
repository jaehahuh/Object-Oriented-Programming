//Author : Jaeha Huh
//Name of File : hw04.cpp
//Description : Noble and Warrior classes contains hire, fire, and battle functions


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class Warrior {

public:
	Warrior(const string warriorName, int strength) : name(warriorName), str(strength), isAlive(true) {
	}
	const string& getName() { return name; }
	void setStr(int strength) {
		str = strength;
	}
	void setAlive(bool isAli) {
		isAlive = isAli;
	}
	int getStr() { return str; }
	bool getAlive() { return isAlive; }


private:
	string name;
	int str;
	bool isAlive;
};


class Noble {
	friend ostream& operator << (ostream& os, const Noble& noble);
public:
	Noble(const string nobleName) : name(nobleName),isAlive(true) {
	}
	void hire(Warrior& warrior) {
		if (isAlive && warrior.getAlive()) {
			for (size_t i = 0; i < hireList.size(); i++) {
				if (hireList[i].getName() == warrior.getName()) {
					cout << warrior.getName() << " is already hired by " << name << endl;
					break;
				}
			}
			hireList.push_back(warrior);
		}
		else if (isAlive) {
			cout << warrior.getName() << " already lost his life in battle" << endl;
		}
		else {
			cout << "How can a dead noble hire someone!" << endl;
		}
	}

	void fire(Warrior& warrior) {
		if (isAlive && warrior.getAlive()) {
			for (size_t i = 0; i < hireList.size(); i++) {
				if (hireList[i].getName() == warrior.getName()) {
					swap(hireList[i],hireList[hireList.size()-1]);
					hireList.pop_back();
				}
				else {
					cout << "You don't work for me anymore " << warrior.getName() << "! -- " << name << "." << endl;
					
				}
			}
		}
		else if (isAlive) {
			cout << warrior.getName() << " already lost his life in battle" << endl;
		}
		else {
			cout << "How can a dead noble fire someone!" << endl;
		}
	}

	void battle(Noble& opponent) {
		string noble1 = name, noble2 = opponent.name;
		cout << noble1 << " battles " << noble2 << endl;
		if (isAlive && opponent.isAlive) {
			int strength1 = 0, strength2 = 0;
			for (size_t i = 0; i < hireList.size(); i++) {
				strength1 += hireList[i].getStr();
			}
			for (size_t i = 0; i < opponent.hireList.size(); i++) {
				strength2 += opponent.hireList[i].getStr();
			}
			if (strength1 == strength2) {
				cout << "Mutual Annihalation: " << noble1 << " and " << noble2 << " die at each other's hands" << endl;
				for (size_t i = 0; i < hireList.size(); i++) {
					hireList[i].setAlive(false);
					hireList[i].setStr(0);
				}
				for (size_t i = 0; i < opponent.hireList.size(); i++) {
					opponent.hireList[i].setAlive(false);
					opponent.hireList[i].setStr(0);
				}
				isAlive = false;
				opponent.isAlive = false;
			}
			else if (strength1 > strength2) {
				cout << noble1 << " defeats " <<  noble2 << endl;
				for (size_t i = 0; i < hireList.size(); i++) {
					hireList[i].setStr(strength1 - strength2);
				}
				for (size_t i = 0; i < opponent.hireList.size(); i++) {
					opponent.hireList[i].setAlive(false);
					opponent.hireList[i].setStr(0);
				}
				opponent.isAlive = false;
			}
			else {
				cout << noble2 << " defeats " << noble1 << endl;
				for (size_t i = 0; i < opponent.hireList.size(); i++) {
					opponent.hireList[i].setStr(strength2 - strength1);
				}
				for (size_t i = 0; i < hireList.size(); i++) {
					hireList[i].setAlive(false);
					hireList[i].setStr(0);
				}
				isAlive = false;
			}
		}
		else if (!isAlive && !opponent.isAlive) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (!isAlive) {
			cout << "He's dead, " << noble1 << endl;
		}
		else {
			cout << "He's dead, " << noble2 << endl;
		}
	}

private:
	string name;
	vector<Warrior> hireList;
	bool isAlive;
};

ostream& operator << (ostream& os, const Noble& noble) {
	size_t armySize = noble.hireList.size();
	os << noble.name << " has an army of " << armySize << endl;
	for (size_t i = 0; i < armySize; i++) {
		Warrior warrior = noble.hireList[i];
		os << "\t" << warrior.getName() << ": " << warrior.getStr() << endl;
	}
	return os;
}


int main() {

	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	cout << "==========\n"
		<< "Status before all battles, etc.\n";
	cout << jim << endl;
	cout << lance << endl;
	cout << art << endl;
	cout << linus << endl;
	cout << billie << endl;
	cout << "==========\n";

	art.fire(cheetah);
	cout << art << endl;

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);

	cout << "==========\n"
		<< "Status after all battles, etc.\n";
	cout << jim << endl;
	cout << lance << endl;
	cout << art << endl;
	cout << linus << endl;
	cout << billie << endl;
	cout << "==========\n";

}
