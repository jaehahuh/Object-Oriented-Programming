//Author:Jaeha Huh
//Name of File : hw05.cpp
//Description : Build warrior and Noble classes then hire and fire warriors by using dynamic memory.


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Warrior {

public:

	Warrior(const string& name, double strength) : name(name), str(strength) {}

	const string getName() const { return name; }

	double getStrength() const { return str; }

	bool hireStatus() const { return hired; }

	bool lifeStatus() const { return alive; }

	void setStrength(double inputStrength) { str = inputStrength; }

	void setHire(bool status) { hired = status; }

	void setAlive(bool status) { alive = status; }

	void display() const { 
		cout << name << " : " << str << endl; 
	}

private:
	string name;
	double str;
	bool alive = true;
	bool hired = false;
};



class Noble {

public:

	Noble(const string& name) : name(name) {}

	bool lifeStatus() const { return alive; }

	const string getName() const { return name; }

	//add warrior in the army
	void hire(Warrior* warrior) {
		army.push_back(warrior);
		warrior->setHire(true);
	}

	//remove warrior from the army
	void fire(Warrior& warrior) {
		cout << "You don't work for me anymore, " << warrior.getName() << "! -- " << name << endl;
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &warrior) {
				army[i] = nullptr;
			}
		}
		warrior.setHire(false);
	}

	void display() const {
		size_t count = 0;
		for (const Warrior* warrior : army) {
			if (warrior != nullptr) {
				++count;
			}
		}
		cout << name << " has an army of " << count << endl;
		for (const Warrior* warrior : army) {
			if (warrior != nullptr) {
				cout << "   ";
				warrior->display();
			}
		}
	}

	//The results of battle
	void battle(Noble& opponent) {
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
		
		//if they are both alive
		else {  
			double selfStr = getArmyStr();
			double opponentStr = opponent.getArmyStr();

			//if they have the same strength, they lose all strength and die
			if (selfStr == opponentStr) { 
				adjustNobleAndArmy(0);
				opponent.adjustNobleAndArmy(0);
				cout << "Mutual Annihilation: " << name << " and " << opponent.getName() << " die at each other's hands." << endl;
			}
			else {
				//if self is weaker
				double weakerStr = min(selfStr, opponentStr);
				if (weakerStr == selfStr && weakerStr != opponentStr) { 
					opponent.adjustNobleAndArmy(0);
					cout << opponent.getName() << " defeats " << name << endl;
					adjustNobleAndArmy(selfStr / opponentStr);
				}
				//if opponent is weaker
				if (weakerStr == opponentStr && weakerStr != selfStr) { 
					opponent.adjustNobleAndArmy(0);
					cout << name << " defeats " << opponent.getName() << endl;
					adjustNobleAndArmy(opponentStr / selfStr);
				}
			}
		}
	}


	void adjustNobleAndArmy(double ratio) {
		if (ratio == 0) {
			alive = false;
			for (Warrior* warrior : army) {
				if (warrior != nullptr) {
					warrior->setStrength(0);
				}
			}
		}
		else {
			for (Warrior* warrior : army) {
				warrior->setStrength(warrior->getStrength() * (1 - ratio));
			}
		}
	}

	//get total army strength
	double getArmyStr() const { 
		double totalStrength = 0;
		for (const Warrior* warrior : army) {
			if (warrior != nullptr) {
				totalStrength += warrior->getStrength();
			}
		}
		return totalStrength;
	}

	//check the enlistment of a warrior
	bool checkArmy(const Warrior& warrior) {
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i] == &warrior) {
				return true;
			}
		}
		return false;
	}

	//deconstructor
	~Noble() {
		while (army.size() != 0) {
			delete army[army.size() - 1];
			army.pop_back();
		}
	}


private:
	vector<Warrior*> army;
	string name;
	bool alive = true;
};



//check status
void status(const vector<Noble*>& nobleList, const vector<Warrior*>& warriorList) {

	cout << "Status" << endl << "=======" << endl << "Nobles:" << endl;

	if (nobleList.size() != 0) {
		for (const Noble* noble : nobleList) {
			noble->display();
		}
	}
	else {
		cout << "None" << endl;
	}

	cout << "Unemployed Warriors:" << endl;

	if (warriorList.size() == 0) {
		cout << "None" << endl;
	}

	else {
		size_t employed = 0;
		for (const Warrior* Warrior : warriorList) {
			if (Warrior->hireStatus() == false) {
				Warrior->display();
			}
			else {
				++employed;
			}
		}
		//if all warriors are currently employed, then none of them are unemployed.
		if (employed == warriorList.size()) { 
			cout << "None!" << endl; 
		}
	}
}



//Find index of nobleList
size_t findNobleIndex(const vector<Noble*>& nobleList, const string& aNoble) {
	for (size_t i = 0; i < nobleList.size(); ++i) {
		if (nobleList[i]->getName() == aNoble) {
			return i;
		}
	}
	return nobleList.size();
}


//Find index of warriorList
size_t findWarriorIndex(const vector<Warrior*>& warriorList, const string& aWarrior) {
	for (size_t i = 0; i < warriorList.size(); ++i) {
		if (warriorList[i]->getName() == aWarrior) {
			return i;
		}
	}
	return warriorList.size();
}




int main() {

	ifstream text("nobleWarriors.txt");
	if (!text) {
		cerr << "Could not open the file" << endl;
		exit(1);
	}

	vector<Warrior*> warriorList;
	vector<Noble*> nobleList;
	string command, noble1, noble2, warrior; 
	int strength; 
	size_t nobleIndex1, nobleIndex2, warriorIndex1; 


	while (text >> command) { 
		if (command == "Warrior") {
			text >> warrior >> strength;
			if (findWarriorIndex(warriorList, warrior) != warriorList.size()) {
				cout << "The warrior exists in list!" << endl;
			}
			else {
				warriorList.push_back(new Warrior(warrior, strength));
			}
		}
		else if (command == "Noble") {
			text >> noble1;
			if (findNobleIndex(nobleList, noble1) != nobleList.size()) {
				cout << "The noble exists in list!" << endl;
			}
			else {
				nobleList.push_back(new Noble(noble1));
			}
		}
		else if (command == "Hire") {
			text >> noble1 >> warrior;
			nobleIndex1 = findNobleIndex(nobleList, noble1);
			warriorIndex1 = findWarriorIndex(warriorList, warrior);
			if (nobleIndex1 == nobleList.size()) {
				cout << "Error: noble " << noble1 << " does not exist!" << endl;
			}
			else if (warriorIndex1 == warriorList.size()) {
				cout << "Error: noble " << noble1 << " is attemping to hire warrior an unknown warrior "
					<< warrior << endl;
			}
			else if (warriorList[warriorIndex1]->hireStatus() == true) {
				cout << "Error: noble " << noble1 << " is attemping to hire warrior "
					<< warrior << " who is already employed" << endl;
			}
			else { //otherwise hire warrior
				nobleList[nobleIndex1]->hire(warriorList[warriorIndex1]);
			}
		}
		else if (command == "Fire") {
			text >> noble1 >> warrior;
			nobleIndex1 = findNobleIndex(nobleList, noble1);
			warriorIndex1 = findWarriorIndex(warriorList, warrior);
			if (nobleIndex1 == nobleList.size()) {
				cout << "Error: noble " << noble1 << " does not exist!" << endl;
			}
			else if (nobleList[nobleIndex1]->lifeStatus() == false) {
				cout << "Error: noble " << noble1 << " is dead so he cannot fire warrior." << endl;
			}
			else if (nobleList[nobleIndex1]->checkArmy(*warriorList[warriorIndex1]) == false) {
				cout << "Error: Warrior " << warrior << " is not in the army!" << endl;
			}
			else { //otherwise fire warrior
				nobleList[nobleIndex1]->fire(*warriorList[warriorIndex1]);
			}
		}
		else if (command == "Status") {
			status(nobleList, warriorList);
		}
		else if (command == "Clear") {
			while (nobleList.size() != 0) {
				nobleList[nobleList.size() - 1] = nullptr;
				nobleList.pop_back();
			}
			while (warriorList.size() != 0) {
				warriorList[warriorList.size() - 1] = nullptr;
				warriorList.pop_back();
			}
		}
		else if (command == "Battle") {
			text >> noble1 >> noble2;
			nobleIndex1 = findNobleIndex(nobleList, noble1);
			nobleIndex2 = findNobleIndex(nobleList, noble2);
			if (nobleIndex1 == nobleList.size()) {
				cout << noble1 << "does not exsit!" << endl;
			}
			else if (nobleIndex2 == nobleList.size()) {
				cout << noble2 << "does not exsit!" << endl;
			}
			else {
				nobleList[nobleIndex1]->battle(*nobleList[nobleIndex2]);
			}
		}
	}
	text.close();
}
