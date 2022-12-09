//Author:Jaeha Huh
//Name of File : rec14.cpp

#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;



// 1 
bool evenBits(int n) {
	if (n == 0) { 
		return true;
	}
	if (evenBits(n / 2)) { 
		if (n % 2 == 1) {
			return false;
		}
		else { return true; }
	}
	else { 
		if (n % 2 == 1) {
			return true;
		}
		else { return false; }
	}
}



// 2

struct Node {
	Node(int data = 0, Node * next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void listDisplay(Node* headPtr) {
	Node* p = headPtr;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

Node* addLists(Node* lst1, Node* lst2) {
	if (!lst1 && !lst2) {
		return nullptr;
	}
	Node* node = new Node();
	if (!lst1) {
		node->data = lst2->data;
		node->next = addLists(lst2->next, nullptr);
		return node;
	}
	if (!lst2) {
		node->data = lst1->data;
		node->next = addLists(lst1->next, nullptr);
		return node;
	}
	node->data = lst1->data + lst2->data;
	node->next = addLists(lst1->next, lst2->next);
	return node;
}




//  3 

struct TNode {
	TNode(int data = 0, TNode * left = nullptr, TNode * right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode* left, * right;
};


int max(TNode* root) {
	//    assert(root != nullptr);
	if (!root) {
		throw logic_error("empty tree");
	}
	if (!root->left && !root->right) { // has no child
		return root->data;
	}
	if (!root->right) { // has left child only
		return max(root->data, max(root->left));
	}
	if (!root->left) { // has right child only
		return max(root->data, max(root->right));
	}
	return max(root->data, max(max(root->left), max(root->right)));
}




//  4 

bool palindrome(char* strChars, size_t size) {
	if (size <= 1) {
		return true;
	}
	if (strChars[0] == strChars[size - 1]) {
		return palindrome(strChars + 1, size - 2);
	}
	return false;
}



// 5 

int tower(int plates, const string& start, const string& spare, const string& target) {
	if (plates == 0) {
		return 0;
	}
	return tower(plates - 1, start, target, spare) + tower(plates - 1, spare, start, target) + 1;
}




// 6 

void mystery(int n) {
	if (n > 1) {
		cout << 'a';
		mystery(n / 2);
		cout << 'b';
		mystery(n / 2);
	}
	cout << 'c';
}




int main() {

	cout << "---------- evenBits test -----------" << endl;
	cout << boolalpha;
	cout << "evenBits(0): " << evenBits(0) << endl;
	cout << "evenBits(1): " << evenBits(1) << endl;
	cout << "evenBits(2): " << evenBits(2) << endl;
	cout << "evenBits(6): " << evenBits(6) << endl;
	cout << "evenBits(32): " << evenBits(32) << endl;

	cout << endl << "--------- addLists test ----------" << endl;
	Node* three = new Node(3, nullptr);
	Node* two = new Node(2, three);
	Node* one = new Node(1, two);

	Node* five = new Node(5, nullptr);
	Node* four = new Node(4, five);

	cout << "List1 : 1 2 3" << endl;
	cout << "List2 : 4 5" << endl;
	cout << "Combined list is: ";
	listDisplay(addLists(one, four));

	cout << endl << "------- max tree test ------- " << endl;
	TNode a(1), b(2), c(4), d(88, &a, &b), e(16, &c), f(32, &d, &e);
	try {
		cout << "max of empty tree is: " << max(nullptr) << endl;
		cout << "max of tree is: " << max(&f) << endl;
	}
	catch (logic_error le) {
		cerr << le.what() << endl;
	}

	cout << endl << "--------- palindrome test --------" << endl;
	char night[] = "night";
	char racecar[] = "racecar";
	char noon[] = "noon";
	cout << "night - " << palindrome(night, 5) << endl;
	cout << "racecar - " << palindrome(racecar,7 ) << endl;
	cout << "noon - " << palindrome(noon, 4) << endl;

	cout << endl << "----------- tower test ---------" << endl;
	cout << "tower(1,a,b,c) " << tower(1, "a", "b", "c") << endl;
	cout << "tower(2,a,b,c) " << tower(2, "a", "b", "c") << endl;
	cout << "tower(3,a,b,c) " << tower(3, "a", "b", "c") << endl;
	cout << "tower(4,a,b,c) " << tower(4, "a", "b", "c") << endl;
	cout << "tower(5,a,b,c) " << tower(5, "a", "b", "c") << endl;
	cout << "tower(6,a,b,c) " << tower(6, "a", "b", "c") << endl;
	cout << "tower(7,a,b,c) " << tower(7, "a", "b", "c") << endl;
	cout << "tower(8,a,b,c) " << tower(8, "a", "b", "c") << endl;


	cout << endl << "---------- Mystery Test ------------" << endl;
	for (int i = 0; i < 17; ++i) {
		cout << i << ":";
		mystery(i);
		cout << endl;
	}
}
