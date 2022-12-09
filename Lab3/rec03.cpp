//Authoer: Jaeha Huh
//File Name: rec03.cpp
//Description: Bank account Class Tutorial 


 // Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// Task 1: The Account struct. Call it AccountS
//
struct AccountS {
	string AccName;
	int AccNum;
};

//
// Task 2: The Account class. Call it AccountC
//
class AccountC {
public:
	friend ostream& operator << (ostream& os, const AccountC& account);
	AccountC(const string& name, int num) : accName(name), accNum(num) {};

	const string& getName() const { return accName;}
	int getNum() const { return accNum; }
	


private:
	string accName;
	int accNum;
};

// 2.b: AccountC output operator, not a friend.

//ostream& operator << (ostream& os, const AccountC& account) {
//	os << "Account Name: " << account.getName() << "Account Number: " << account.getNum() << endl;
//	return os;
//}

// 2.2: AccountC output operator, reimplemented as a friend.
ostream& operator << (ostream& os, const AccountC& account) {
	os << "Account Name: " << account.accName << " , Account Number: " << account.accNum << endl;
	return os;
}



//
// Task 3
//
// Transaction class definition
class Transaction {
public:
	Transaction(bool act, int amount) : transAct(act), transAmount(amount) {}

	void display() {
		if (transAct) {
			cout << "Deposit: " << transAmount << endl;
		}
		else{
			cout << "withdraw: " << transAmount << endl;
		}
	}
	
private:
	bool transAct;
	int transAmount;
};

// Account class definition
class Account {
public:
	friend ostream& operator << (ostream& os, const Account& account);
	Account(const string& name, int num) : accName(name), accNum(num) {
		balance = 0;
	}

	const string& getName() const { return accName; }
	int getNum() const { return accNum; }

	void deposit(int amount) {
		Transaction trans(true, amount); 
		statement.push_back(trans); 
		balance = balance + amount; 
		cout << "After Deposit :" << balance << endl;
	}
	void withdraw(int amount)
	{
		if (amount <= balance) { 
			Transaction trans(false, amount); 
			statement.push_back(trans); 
			balance = balance - amount; 
			cout << "After Withdraw :" << balance << endl;
		}
		else
			cout << "Insufficeint balance" << endl;
	}
private:
	string accName;
	int accNum;
	int balance;
	vector <Transaction> statement;
};

ostream& operator << (ostream& os, const Account& account)
{
	cout << "Account Name: " << account.accName << endl;
	cout << "Account Number: " << account.accNum << endl;
	cout << "Account balance: " << account.balance << endl;
	cout << "Transaction Statements: " << endl;
	for (Transaction Trans : account.statement) {
		Trans.display();
	}
	return os;
}
//
// Task 4
//
// Transaction class definition with embedded Account class


class Account2 {
public:
	class Transaction2 {
	public:
		Transaction2(bool act, int amount) : transAct(act), transAmount(amount) {}

		void display() {
			if (transAct) {
				cout << "Deposit: " << transAmount << endl;
			}
			else {
				cout << "withdraw: " << transAmount << endl;
			}
		}

	private:
		bool transAct;
		int transAmount;
	};

	friend ostream& operator << (ostream& os, const Account2& account);
	Account2(const string& name, int num) : accName(name), accNum(num) {
		balance = 0;
	}

	const string& getName() const { return accName; }
	int getNum() const { return accNum; }

	void deposit(int amount) {
		Transaction2 trans(true, amount);
		statement.emplace_back(trans);
		balance = balance + amount;
		cout << "After Deposit :" << balance << endl;
	}
	void withdraw(int amount)
	{
		if (amount <= balance) {
			Transaction2 trans(false, amount);
			statement.emplace_back(trans);
			balance = balance - amount;
			cout << "After Withdraw :" << balance << endl;
		}
		else
			cout << "Insufficeint balance" << endl;
	}
private:
	string accName;
	int accNum;
	int balance;
	vector <Transaction2> statement;
};

ostream& operator << (ostream& os, const Account2& account)
{
	cout << "Account Name: " << account.accName << endl;
	cout << "Account Number: " << account.accNum << endl;
	cout << "Account balance: " << account.balance << endl;
	cout << "Transaction Statements: " << endl;
	for (Account2 :: Transaction2 Trans : account.statement) {
		Trans.display();
	}
	return os;
}





int main() {



	// Task 1: account as struct
	//
	//      1a. Fill vector of account structs from file
	cout << "Task1a:\n";
	cout << "Filling vector of struct objects, define a local struct instance "
		<< " and set fields explicitly:\n";

	ifstream accStruct1("accounts.txt");
	if (!accStruct1) {
		cerr << "could not open the file" << endl;;
		exit(1);
	}

	vector<AccountS> accList;
	string name;
	int num;
	while (accStruct1 >> name >> num) {
		AccountS accInfo;
		accInfo.AccName = name;
		accInfo.AccNum = num;
		accList.push_back(accInfo);
	}
	
	accStruct1.close();
	for (size_t i = 0; i < accList.size(); ++i) {
		cout << accList[i].AccName <<" "<< accList[i].AccNum << endl;
	}
	
	

	//      1b
	cout << endl;
	cout << "Task1b:\n";
	cout << "Filling vector of struct objects, using {} initialization:\n";

	accList.clear();


	ifstream accStruct2("accounts.txt");
	if (!accStruct2) {
		cerr << "Could not open this file" << endl;
		exit(1);
	}
	
	vector<AccountS> accList1;
	string name1;
	int num1;

	while (accStruct2 >> name1 >> num1) {
		AccountS accInfo1{ name1, num1 };
		accList1.push_back(accInfo1);
	}
	accStruct2.close();

	for (size_t i = 0; i < accList1.size(); ++i) {
		cout << accList1[i].AccName << " " << accList1[i].AccNum << endl;
	}


	//==================================
	//
	// Task 2: account as class
	//

	//      2a
	cout << "==============\n";
	cout << "\nTask2a:";
	cout << "\nFilling vector of class objects, using local class object:\n";



	cout << "---\n";
	cout << "\nTask2b:\n";
	cout << "output using output operator with getters\n";


	cout << "\nTask2c:\n";
	cout << "output using output operator as friend without getters\n";
	// Note code here will be same as above.


	cout << "\nTask2d:\n";
	cout << "Filling vector of class objects, using temporary class object:\n";
	
	//ifstream accClass1("accounts.txt");
	//if (!accClass1) {
	//	cerr << "could not open the file" << endl;;
	//	exit(1);
	//}

	//vector<AccountC> accountList;
	//string name2;
	//int num2;
	//while (accClass1 >> name2 >> num2) {
	//	AccountC accountInfo(name2, num2);
	//	accountList.push_back(accountInfo);
	//}
	//accClass1.close();

	//for (size_t i = 0; i <= accountList.size() - 1; ++i) {
	//	cout << accountList[i] << endl;
	//}



	cout << "\nTask2e:\n";
	cout << "\nFilling vector of class objects, using emplace_back:\n";

	ifstream accClass2("accounts.txt");
	if (!accClass2) {
		cerr << "could not open the file" << endl;;
		exit(1);
	}

	vector<AccountC> accountList;
	string name2;
	int num2;
	while (accClass2 >> name2 >> num2) {
		AccountC accountInfo(name2, num2);
		accountList.emplace_back(accountInfo);
	}
	accClass2.close();

	for (size_t i = 0; i <= accountList.size() - 1; ++i) {
		cout << accountList[i] << endl;
	}
	

	// Task 3
	cout << "==============\n";
	cout << "\nTask 3:\n\nAccounts and Transaction:\n";

	ifstream transFile("transactions.txt");
	if (!transFile) {
		cerr << "failed to open transactions.txt";
		exit(1);
	}

	vector<Account> ListOfAccount;
	string type;
	

	while (!transFile.eof()) {
		transFile >> type;
		if (type == "Account") {
			string nameOfaccount;
			int numOfaccount;
			transFile >> nameOfaccount >> numOfaccount;
			Account acc(nameOfaccount, numOfaccount);
			ListOfAccount.emplace_back(acc);
		}
		if (type == "Deposit") {
			int numOfaccount;
			int amount;
			transFile >> numOfaccount >> amount;
			for (size_t i = 0; i < ListOfAccount.size(); ++i)
			{
				if (ListOfAccount[i].getNum() == numOfaccount) 
				{
					ListOfAccount[i].deposit(amount);
					break;
				}
			}
		}
		if (type == "Withdraw") {
			int numOfaccount;
			int amount;

			transFile >> numOfaccount >> amount;
			for (size_t i = 0; i < ListOfAccount.size(); ++i)
			{
				if (ListOfAccount[i].getNum() == numOfaccount)
				{
					ListOfAccount[i].withdraw(amount);
					break;
				}
			}
		}
	}
	
	transFile.close();

	for (size_t i = 0; i < ListOfAccount.size(); ++i)
	{
		cout << ListOfAccount[i] << endl; 
	}




	// Task 4
	cout << "==============\n";
	cout << "\nTask 4:\n\nAccounts and Transaction:\n"
		<< "Account class is nested inside Transaction class.\n";

	ifstream transFile2("transactions.txt");
	if (!transFile2) {
		cerr << "failed to open transactions.txt";
		exit(1);
	}

	vector<Account2> ListOfAccount2;
	string type2;


	while (!transFile2.eof()) {
		transFile2 >> type2;

		if (type2 == "Account") {
			string nameOfaccount2;
			int numOfaccount2;
			transFile2 >> nameOfaccount2 >> numOfaccount2;
			Account acc2(nameOfaccount2, numOfaccount2);
			ListOfAccount2.emplace_back(acc2);
		}

		if (type == "Deposit") {
			int numOfaccount2;
			int amount2;
			transFile2 >> numOfaccount2 >> amount2;
			for (size_t i = 0; i < ListOfAccount2.size(); ++i)
			{
				if (ListOfAccount2[i].getNum() == numOfaccount2)
				{
					ListOfAccount2[i].deposit(amount2);
					break;
				}
			}
		}
		if (type == "Withdraw") {
			int numOfaccount2;
			int amount2;

			transFile2 >> numOfaccount2 >> amount2;
			for (size_t i = 0; i < ListOfAccount2.size(); ++i)
			{
				if (ListOfAccount2[i].getNum() == numOfaccount2)
				{
					ListOfAccount2[i].withdraw(amount2);
					break;
				}
			}
		}
	}

	transFile2.close();

	for (size_t i = 0; i < ListOfAccount2.size(); ++i)
	{
		cout << ListOfAccount2[i] << endl;
	}


}

