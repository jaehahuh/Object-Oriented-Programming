//Author: Jaeha Huh
//Name of File: hw02.cpp
//Description: It shows the results of a battle between warriors.


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


//Prototypes
struct Warrior;
void warriorInfo(ifstream& text, vector<Warrior>& warriorList);
void battle(ifstream& text, vector<Warrior>& warriorList);
size_t findIndex(const vector<Warrior>& warriorList, const string& warriorName);
void status(const vector<Warrior>& warriorList);




struct Warrior {
	string name;
	int str;
};



int main() {
	ifstream text("warriors.txt");
	if (!text) {
		cerr << "Could not open the file" << endl;
		exit(1);
	}

	string word;
	vector<Warrior> warriorList;
	while (text >> word) {
		if (word == "Status") {
			status(warriorList);
		}
		else if (word == "Warrior") {
			warriorInfo(text, warriorList);
		}
		else if (word == "Battle") {
			battle(text, warriorList);
		}
	}
	text.close();
}


//make a new warrior and then push into the vector of warriorList
void warriorInfo(ifstream& text, vector<Warrior>& warriorList) {
	Warrior warrior;
	text >> warrior.name >> warrior.str;
	warriorList.push_back(warrior);
}


//display the result of battle.
void battle(ifstream& text, vector<Warrior>& warriorList) {
	string warriorOne, warriorTwo;
	int first, second;
	text >> warriorOne >> warriorTwo;
	first = findIndex(warriorList, warriorOne);
	second = findIndex(warriorList, warriorTwo);

	cout << warriorList[first].name << " battles " << warriorList[second].name << endl;


	if (warriorList[first].str == 0 && warriorList[second].str == 0) {
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}

	else if (warriorList[first].str != 0 && warriorList[second].str == 0) {
		cout << "He's dead, " << warriorList[first].name << endl;
	}

	else if (warriorList[first].str == 0 && warriorList[second].str != 0) {
		cout << "He's dead, " << warriorList[second].name << endl;
	}

	else if (warriorList[first].str == warriorList[second].str) {
		cout << "Mutual Annihilation: " << warriorList[first].name << " and "
			<< warriorList[second].name << " die at each other's hands" << endl;
		warriorList[first].str = 0;
		warriorList[second].str = 0;
	}

	else if (warriorList[first].str > warriorList[second].str) {
		cout << warriorList[first].name << " defeats " << warriorList[second].name << endl;
		warriorList[first].str = warriorList[first].str - warriorList[second].str;
		warriorList[second].str = 0;
	}

	else if (warriorList[first].str < warriorList[second].str) {
		cout << warriorList[second].name << " defeats " << warriorList[first].name << endl;
		warriorList[second].str = warriorList[second].str - warriorList[first].str;
		warriorList[first].str = 0;
	}

}


//find a warrior's index in the warrior List
size_t findIndex(const vector<Warrior>& warriorList, const string& warriorName) {
	for (size_t i = 0; i < warriorList.size(); ++i) {
		if (warriorList[i].name == warriorName) {
			return i;
		}
	}
}


//display status of warriors
void status(const vector<Warrior>& warriorList) {
	cout << "Theree are: " << warriorList.size() << " warriors" << endl;
	for (size_t i = 0; i < warriorList.size(); ++i) {
		cout << "Warrior: " << warriorList[i].name << ", Strength: " << warriorList[i].str << endl;
	}
}








