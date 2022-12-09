//Author: Jaeha Huh
//Name of File: rec11.cpp

#include <iostream>
#include <vector>
using namespace std;


// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node * next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
	while (headPtr) {
		Node* next = headPtr->next;
		delete headPtr;
		headPtr = next;
	}
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
	Node* result = nullptr;
	for (size_t index = vals.size(); index > 0; --index) {
		listAddHead(result, vals[index - 1]);
	}
	return result;
}

//Task one
void splice(Node* originalListPtr, Node* newListPtr) {
	Node* p = newListPtr;
	if (!p) {
		return; // check 
	}
	while (p->next) {
		p = p->next;
	}
	p->next = originalListPtr->next;
	originalListPtr->next = newListPtr;
}

void listDisplay(const Node* headPtr) {
	const Node* p = headPtr;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

//Task two
const Node* isSublist(const Node* sublistHead, const Node* target) {

	// dont need const node (pointer); unnessary;
	const Node* sub = sublistHead;
	const Node* tar = target;
	const Node* firstMatch = nullptr;

	while (tar) {
		if (tar->data == sublistHead->data) { //if first ones match
			firstMatch = tar;
			const Node* newTar = tar;

			while (sub && newTar) {
				if (newTar->data == sub->data) {
					newTar = newTar->next;
					sub = sub->next;
				}
				else {
					firstMatch = nullptr;
					sub = sublistHead;
					tar = tar->next;
					break;
				}
			}
			if (sub == nullptr) {
				break;
			}
			else {
				firstMatch = nullptr;
			}
		}
		else { tar = tar->next; }
	}
	return firstMatch;
}

void display(const Node* p) {
	if (p) {
		const Node* pp = p;
		while (pp) {
			cout << pp->data << " ";
			pp = pp->next;
		}
		cout << endl;
	}
	else {
		cout << "Failed to match " << endl;
	}
}

//Task three
const Node* sharedListBruteForce(const Node* first, const Node* second) {
	const Node* fir = first;
	const Node* sec = second;

	while (fir) {
		if (sec == nullptr) { sec = second; }
		while (sec) {
			if (&fir->next == &sec->next) {
				return fir->next;
			}
			sec = sec->next;
		}
		fir = fir->next;
	}
	return nullptr;
}


int main() {
	
	//Task One
	Node* original = listBuild({5,7,9,1});
    Node* newNode = listBuild({6,3,2});
    cout << "L1: ";
    listDisplay(original);
    cout << "L2: ";
    listDisplay(newNode);

    int index = 0;
    Node* targetNode = original;
	
    while (index != 1){
        targetNode = targetNode->next;
        ++index;
    }

	cout << "Target: ";
	listDisplay(targetNode);

	cout << "Splicing L2 at target in L1" << endl;
    splice(targetNode, newNode);

	cout << "L1: ";
	listDisplay(original);
	cout << "L2: ";
	listDisplay(newNode);
    cout << endl;



	//Task Two
	const Node* list = listBuild({ 1,2,3,2,3,2,4,5,6 });
	cout << "list: ";
	listDisplay(list);
	cout << endl;
	
	const Node* sub1 = listBuild({1});
	cout << "Attempt match: ";
	listDisplay(sub1);
	const Node* p1 = isSublist(sub1, list);
	display(p1);
	cout << endl;
	
	const Node* sub2 = listBuild({3,9});
	cout << "Attempt match: ";
	listDisplay(sub2);
	const Node* p2 = isSublist(sub2, list);
	display(p2);
	cout << endl;
	
	const Node* sub3 = listBuild({2,3});
	cout << "Attempt match: ";
	listDisplay(sub3);
	const Node* p3 = isSublist(sub3, list);
	display(p3);
	cout << endl;
	
	const Node* sub4 = listBuild({2,4,5,6});
	cout << "Attempt match: ";
	listDisplay(sub4);
	const Node* p4 = isSublist(sub4, list);
	display(p4);
	cout << endl;
	
	const Node* sub5 = listBuild({2,3,2,4});
	cout << "Attempt match: ";
	listDisplay(sub5);
	const Node* p5 = isSublist(sub5, list);
	display(p5);
	cout << endl;
	
	const Node* sub6 = listBuild({5,6,7});
	cout << "Attempt match: ";
	listDisplay(sub6);
	const Node* p6 = isSublist(sub6, list);
	display(p6);
	cout << endl;

	const Node* sub7 = listBuild({ 6 });
	cout << "Attempt match: ";
	listDisplay(sub7);
	const Node* p7 = isSublist(sub7, list);
	display(p7);
	cout << endl;

	//Task Three
	Node* list1 = listBuild({ 2,3,4,5 });
	Node* list2 = listBuild({ 2,3,3 });
	Node* p8 = list1;
	Node* p9 = list2;

	for (size_t i = 0; i < 2; ++i) {
		p8 = p8->next;
	}

	while (p9->next) {
		p9 = p9->next;
	}

	p9->next = p8;

	cout << "list1: " << endl;
	listDisplay(list1);
	cout << "list2: " << endl;
	listDisplay(list2);

	const Node* pp1 = sharedListBruteForce(list1, list2);

	listDisplay(pp1);
}

