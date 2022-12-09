//Author : Jaeha Huh
//Name of File : rec01.cpp
//Description : Tutorial

#include <iostream>	
#include <fstream>
#include <vector>

using namespace std;

//const : protect modify data
//& : take real data (can modify)
//without &  : just copy data (can't modify real data)
void vectorFunc1(const vector<int>&  ints) {  
	for (size_t i = 0; i < ints.size(); ++i) {
		cout << ints[i] << " ";
	}
	cout << endl;
}

void vectorFunc2(vector<int>& ints) { 
	for (size_t i = 0; i < ints.size(); ++i) {
		ints[i] = ints[i] * 2;
	}
	cout << endl;
}

void vectorFunc3(vector<int>& ints) {
	for (int& value : ints) {
		value = value * 2;
	}
	cout << endl;
}

int main() {
    std::cout << "hello 1" << std::endl;
	cout << "Hello 2" << endl;

	//int x = "felix";    // It is compilation error;
	//cout << "x = " << x << endl;
	//cout << sizeof(x) <<endl;

	int y = 17;
	int z = 2000000017;
	double pie = 3.14159;
	cout << sizeof(y) << endl;
	cout << sizeof(z) << endl;
	cout << sizeof(pie) << endl;

	if (y >= 10 && y <= 20) {
		cout << "y is between 10 and 20" << endl;
	}
	else {
		cout << "y is not between 10 and 20" << endl;
	}



	for (int i = 10; i <= 20; i++) {
		cout << i << " ";
		
	}
	cout << endl;


	int i = 10;
	while (i <= 20) {
		cout << i << " ";
		++i;
	}
	cout << endl;

	
	int j = 10;
	do {
		cout << j << " ";
		++j;
	} while (j <= 20);
	cout << endl;


	ifstream text;
	string filename;
	cout << "Enter the file name :";
	cin >> filename;
	text.open(filename);  //filename.c_str();
	while (!text) {
		cout << "Incorrect file name, Re-enter the file name: ";
		cin >> filename;
		text.open(filename);
	}
	
	string word;
	while (text >> word) {
		cout << word << endl;
	}
	text.close();


	vector<int> nums;
	for (int i = 10; i <= 100; i=i+2) {
		nums.push_back(i);
	}
	
	//using indices
	for (size_t j = 0; j < nums.size(); ++j) {
		cout << nums[j] << " ";
	}
	cout << endl;

	//using ranged for
	for (int value : nums) {
		cout << value << " ";
	}
	cout << endl;

	//reverse
	for (size_t z = nums.size();  z > 0; --z){
		cout << nums[z-1] << " ";
	
	}
	cout << endl;

	cout << "Prime numbers" << endl;
	vector<int> primes;
	for (int num = 0; num < 20; ++num){
		bool flag = true;
		if (num == 0 || num == 1) {
			flag = false;
		}
		for (int i = 2; i <= num / 2; ++i) {
			if (num % i == 0){
				flag = false;
			}
		}	
		if (flag == true) {
			primes.push_back(num);
		}
	}	

	for (int value : primes) {
		cout << value << " ";
	}
	cout << endl;

	cout << endl;



	//Functions
	vector<int> ints = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vectorFunc1(ints);
	vectorFunc2(ints);
	vectorFunc3(ints);
}








