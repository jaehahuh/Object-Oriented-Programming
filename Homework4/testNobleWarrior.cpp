
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Your Noble and Warrior classes should go here.
class Warrior {

public:
	Warrior(const string warriorName, int warriorStrength) {
		name = warriorName;
		strength = warriorStrength;
		isAlive = true;
	}

private:
	string name;
	int strength;
	bool isAlive;
};

bool operator==(const Warrior& lhs, const Warrior& rhs) {
	if (lhs.name == rhs.name && lhs.strength == rhs.strength) {
		return true;
	}
	return false;
};

class Noble {
public:
	Noble(const string nobleName) : name(nobleName) {
		isAlive = true;
	}
	void hire(Warrior& warrior) {
		if (isAlive && warrior.isAlive) {
			vector<Warrior>::iterator it = find(hireList.begin(), hireList.end(), warrior);
			if (it != hireList.end()) {
				cout << warrior.name << " is already hired by " << name << endl;
			}
			else {
				hireList.push_back(warrior);
			}
		}
		else if (isAlive) {
			cout << warrior.name << " already lost his life in battle" << endl;
		}
		else {
			cout << "How can a dead noble hire someone!" << endl;
		}
	}
	void fire(Warrior& warrior) {
		if (isAlive && warrior.isAlive) {
			vector<Warrior>::iterator it = find(hireList.begin(), hireList.end(), warrior);
			if (it != hireList.end()) {
				hireList.erase(it);
			}
			else {
				cout << warrior.name << " is not in " << name << " army" << endl;
			}
		}
		else if (isAlive) {
			cout << warrior.name << " already lost his life in battle" << endl;
		}
		else {
			cout << "How can a dead noble fire someone!" << endl;
		}
	}
	void battle(Noble& opponent) {
		string p1 = name, p2 = opponent.name;
		cout << p1 << " battles " << p2 << endl;
		if (isAlive && opponent.isAlive) {
			vector<Warrior> warriorsP1 = hireList;
			vector<Warrior> warriorsP2 = opponent.hireList;
			int strengthP1 = 0, strengthP2 = 0, armySizeP1 = warriorsP1.size(), armySizeP2 = warriorsP2.size();
			for (int i = 0; i < armySizeP1; i++) {
				strengthP1 += warriorsP1[i].strength;
			}
			for (int i = 0; i < armySizeP2; i++) {
				strengthP2 += warriorsP2[i].strength;
			}
			if (strengthP1 == strengthP2) {
				cout << "Mutual Annihalation: " << p1 << " and " << p2 << " die at each other's hands" << endl;
				for (int i = 0; i < armySizeP1; i++) {
					warriorsP1[i].isAlive = false;
				}
				for (int i = 0; i < armySizeP2; i++) {
					warriorsP2[i].isAlive = false;
				}
				isAlive = false;
				opponent.isAlive = false;
			}
			else if (strengthP1 > strengthP2) {
				cout << p1 << " defeats " << p2 << endl;
				float casualtyFactor = 1.0 * (strengthP2 / strengthP1);
				for (int i = 0; i < armySizeP1; i++) {
					warriorsP1[i].strength *= (1 - casualtyFactor);
				}
				for (int i = 0; i < armySizeP2; i++) {
					warriorsP2[i].isAlive = false;
				}
				opponent.isAlive = false;
			}
			else {
				cout << p2 << " defeats " << p1 << endl;
				float casualtyFactor = 1.0 * (strengthP1 / strengthP2);
				for (int i = 0; i < armySizeP2; i++) {
					warriorsP2[i].strength *= (1 - casualtyFactor);
				}
				for (int i = 0; i < armySizeP1; i++) {
					warriorsP1[i].isAlive = false;
				}
				isAlive = false;
			}
		}
		else if (!isAlive && !opponent.isAlive) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (!isAlive) {
			cout << "He's dead, " << p1 << endl;
		}
		else {
			cout << "He's dead, " << p2 << endl;
		}
	}

private:
	string name;
	vector<Warrior> hireList;
	bool isAlive;
};

ostream& operator << (ostream& os, const Noble& noble){
	int armySize = hireList.size();
	cout << name << " has an army of " << armySize << endl;
	for (int i = 0; i < armySize; i++) {
		Warrior warrior = hireList[i];
		cout << "\t" << warrior.name << ": " << warrior.strength << endl;
	}
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
