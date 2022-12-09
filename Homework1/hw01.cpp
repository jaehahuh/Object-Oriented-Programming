//Author: Jaeha Huh
//File Name : hw01.cpp
//Description: Decrypt the encrypted file.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Prototypes
void decryptText(int num, string& word);
char decryptchar(int num, char& ch);



int main() {
	
	ifstream enc("encrypted.txt ");
	if (!enc) {
		cerr << "Could not open the file" << endl;
		exit(1);
	}

	int num;
	vector <string> crypto;
	string line;

	enc >> num;
	while (getline(enc, line)) {
		crypto.push_back(line);
	}
	
	//Decrypt each lines of encrypted text
	for (size_t word = 0; word < crypto.size(); ++word) { 
		decryptText(num, crypto[word]);
	}

	//Print the decrypted text in reversed order
	for (int i = crypto.size() - 1; i > 0; --i) {
		cout << crypto[i] << endl;
	}

	enc.close();
}


//Decrypt each word of encrypted lines.
void decryptText(int num, string& word) {
	
	for (size_t ch = 0; ch < word.size(); ++ch) {
		word[ch] = decryptchar(num, word[ch]);
	}
}


//Decrypt each characters of a encrypted word. 
char decryptchar(int num, char& ch) {

	if (islower(ch)) {
		ch = ch - num;

		if (ch < 'a') {
			ch = ch + 'z' - 'a' + 1;
		}
	}
	return ch;
}
