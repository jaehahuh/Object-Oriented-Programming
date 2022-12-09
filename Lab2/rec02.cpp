//Author : Jaeha Huh
//Name of File : rec02.cpp
//Description: read formulas and sort them in order.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Chem {
	vector<string> name;
	int carbon;
	int hydro;
};

void openFile(ifstream& chemical, string& filename) {
	cout << "Enter the file name: ";
	cin >> filename;
	chemical.open(filename);
	while (!chemical) {
		cout << "File name is wrong. Enter the file name: ";
		cin >> filename;
		chemical.open(filename);
	}
}

int checkDuplicate(const vector<Chem>& formula, int numC, int numH) {
	for (size_t i = 0; i < formula.size(); i++) {
		if (formula[i].carbon == numC && formula[i].hydro == numH) {
			return i;
		}
		
	}
	return formula.size();
}

void insert(vector<Chem>& formula, string name, int numC, int numH) {
	Chem molecule;
	vector <string> list;
	list.push_back(name);
	molecule.name = list;
	molecule.carbon = numC;
	molecule.hydro = numH;
	formula.push_back(molecule);
}

void sort(vector<Chem>& formula) {
	for (int i = 0; i < formula.size(); i++) {
		for (int j = 0; j < formula.size()-i-1; j++) {
			if (formula[j].carbon == formula[j + 1].carbon 
				&& formula[j].hydro > formula[j + 1].hydro) {
				Chem sortHydro = formula[j];
				formula[j] = formula[j + 1];
				formula[j + 1] = sortHydro;
			}
			else if (formula[j].carbon > formula[j + 1].carbon) {
				Chem sortCarbon = formula[j];
				formula[j] = formula[j + 1];
				formula[j + 1] = sortCarbon;
			}
		}
	}
}


int main() {

	ifstream chemical;
	string filename;
	
	openFile(chemical, filename);

	//Read File
	char c, h;
	int numC, numH;
	string chem;
	vector <Chem> formula;

	while (chemical >> chem >> c >> numC >> h >> numH) {
		// check duplicate formula (function)
		int index = checkDuplicate(formula, numC, numH);

		//if there is no duplicated formula
		if (index == formula.size()) {
			insert(formula, chem, numC, numH);
		}
		else {
			formula[index].name.push_back(chem);
		}

	}

	sort(formula);
	for (size_t i = 0; i < formula.size(); i++) {
		cout << "C" << formula[i].carbon << "H" << formula[i].hydro << " ";
		for (size_t j = 0; j < formula[i].name.size(); j++) {
			cout << formula[i].name[j] << " ";
		}
		cout << endl;
	}




	chemical.close();
}