//Author : Jaeha Huh
//Name of File : hw03.cpp
//Description : Create a class of warriors and weapons, and show the results and status of the battle.

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


//prototypes
class Warrior;
class Weapon;
size_t findIndex(const vector<Warrior>& warriorList, const string& warriorName);



class Warrior {
public:
	friend ostream& operator << (ostream& os, const Warrior& warrior);

	class Weapon {
	public:
		friend ostream& operator << (ostream& os, const Warrior& warrior);
		Weapon(const string& name, int strength) : weaName(name), str(strength) {}

		const string& getName() { return weaName; }
		int getStr() { return str; }

		void setStr(int strength) {
			str = strength;
		}

	private:
		string weaName;
		int str;
	};


	Warrior(const string& name, Weapon& weapon) : warName(name), weaponInfo(weapon) {
	}

	const string& getName() const { return warName; }
	Weapon& getWeapon() { return weaponInfo; }


	//Check if the warrior is dead
	bool isDead() {
		if (weaponInfo.getStr() == 0)
			return true;
		else {
			return false;
		}
	}

	//The results of battle
	void battle(Warrior& enemy) {
		cout << warName << " battles " << enemy.getName() << endl;
		if (weaponInfo.getStr() > enemy.getWeapon().getStr()
			&& isDead() == false && enemy.isDead() == false) {
			cout << warName << " defeats " << enemy.getName() << endl;
			weaponInfo.setStr(weaponInfo.getStr() - enemy.getWeapon().getStr());
			enemy.getWeapon().setStr(0);
		}

		else if (weaponInfo.getStr() < enemy.getWeapon().getStr()
			&& isDead() == false && enemy.isDead() == false) {
			cout << enemy.getName() << " defeats " << warName << endl;
			enemy.getWeapon().setStr(enemy.getWeapon().getStr() - weaponInfo.getStr());
			weaponInfo.setStr(0);
		}

		else if (isDead() == false && enemy.isDead() == true) {
			cout << "He's dead, " << warName << endl;
		}

		else if (isDead() == true && enemy.isDead() == false) {
			cout << "He's dead, " << enemy.getName() << endl;
		}

		else if (weaponInfo.getStr() == enemy.getWeapon().getStr()
			&& isDead() == false && enemy.isDead() == false) {
			cout << "Mutual Annihilation: " << warName << " and " << enemy.getName() << " die at each other's hands" << endl;
			weaponInfo.setStr(0);
			enemy.getWeapon().setStr(0);
		}

		else if (isDead() == true && enemy.isDead() == true) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
	}

private:
	string warName;
	Weapon weaponInfo;
};


//Display status
ostream& operator << (ostream& os, const Warrior& warrior) {
	os << "Warrior: " << warrior.warName << ", weapon: " << warrior.weaponInfo.weaName
		<< ", " << warrior.weaponInfo.str;
	return os;
}


//Find index of warrior from the warrior list
size_t findIndex(const vector<Warrior>& warriorList, const string& warriorName) {
	for (size_t i = 0; i < warriorList.size() - 1; ++i) {
		if (warriorList[i].getName() == warriorName) {
			return i;
		}
	}
	return warriorList.size() - 1;

}



int main() {
	ifstream text("warriors.txt");
	if (!text) {
		cerr << "Could not open the file" << endl;
		exit(1);
	}

	string word, weaponName, warriorName;
	vector <Warrior> warriorList;
	int str;
	while (text >> word) {
		if (word == "Status") {
			cout << "There are: " << warriorList.size() << " warriors" << endl;
			for (size_t i = 0; i <= warriorList.size() - 1; ++i) {
				cout << warriorList[i] << endl;
			}
		}
		else if (word == "Warrior") {
			text >> warriorName >> weaponName >> str;
			Warrior::Weapon weapon(weaponName, str);
			Warrior warrior(warriorName, weapon);
			warriorList.push_back(warrior);
		}
		else if (word == "Battle") {
			string warrior1, warrior2;
			text >> warrior1 >> warrior2;
			int first, second;
			first = findIndex(warriorList, warrior1);
			second = findIndex(warriorList, warrior2);
			warriorList[first].battle(warriorList[second]);
		}

	}
	text.close();
}