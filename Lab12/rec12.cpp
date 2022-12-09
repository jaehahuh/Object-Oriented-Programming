//Author: Jaeha Huh
//File Name: rec12.cpp

#include <cstdlib>
#include <iostream>
using namespace std;


class List {
	struct Node {
		Node(int data = 0, Node * prev = nullptr, Node * next = nullptr) : data(data), prev(prev), next(next) {}
		int data;
		Node* prev;
		Node* next;
	};
	friend ostream& operator<<(ostream& os, const Node* node) {
		os << node->data;
		return os;
	}
	friend ostream& operator<<(ostream& os, const List& rhs) {
		Node* ind = rhs.head->next;
		while (ind != rhs.tail) {
			os << ind->data << " ";
			ind = ind->next;
		}
		return os;
	}
public:
	class iterator {
		friend class List;
	public:
		iterator(Node* node) : node(node) {}
		iterator& operator++() {
			node = node->next;
			return *this;
		}
		iterator& operator--() {
			node = node->prev;
			return *this;
		}
		bool operator==(const iterator& iter) { return &node == &iter.node; }
		bool operator!=(const iterator& iter) { return !(node == iter.node); }
		int operator*()const { return node->data; }
		const int& operator*() { return node->data; }
	private:
		Node* node;
	};
	List() :length(0), head(new Node), tail(new Node) {
		head->next = tail;
		tail->prev = head;
	}
	~List() {
		clear();
		delete head;
		delete tail;
	}
	//    assignment operator
	//    copy constructor
	void push_back(int data) {
		Node* node = new Node(data, tail->prev, tail);
		tail->prev->next = node;
		tail->prev = node;
		++length;
	}
	void push_front(int data) {
		Node* node = new Node(data, head, head->next);
		head->next->prev = node;
		head->next = node;
		++length;
	}
	void pop_back() {
		Node* ind = tail->prev;
		ind->prev->next = tail;
		tail->prev = ind->prev;
		delete ind;
		--length;
	}
	void pop_front() {
		Node* node = head->next;
		head->next = node->next;
		node->next->prev = head;
		delete node;
		--length;
	}
	iterator insert(const iterator& iter, int data) {
		Node* node = new Node(data, iter.node->prev, iter.node);
		iter.node->prev->next = node;
		iter.node->prev = node;
		++length;
		return iterator(node);
	}
	iterator erase(const iterator& iter) {
		Node* after = iter.node->next;
		iter.node->prev->next = iter.node->next;
		iter.node->next->prev = iter.node->prev;
		delete iter.node;
		--length;
		return after;
	}
	void clear() {
		while (length > 0) {
			pop_back();
		}
	}
	int& operator[](size_t ind) {
		Node* node = head->next;
		for (size_t i = 0; i < ind; ++i) {
			node = node->next;
		}
		return node->data;
	}
	const int& operator[](size_t ind) const {
		Node* node = head->next;
		for (size_t i = 0; i < ind; ++i) {
			node = node->next;
		}
		return node->data;
	}

	iterator begin()const { return iterator(head->next); }
	iterator end()const { return iterator(tail); }

	const int& front() const {
		return head->next->data;
	}
	int& front() {
		return head->next->data;
	}
	const int& back() const {
		return tail->prev->data;
	}
	int& back() {
		return tail->prev->data;
	}
	int size() const { return length; }

private:
	Node* head;
	Node* tail;
	int length;
};

// Task 1
void printListInfo(const List& myList) {
	cout << "size: " << myList.size()
		<< ", front: " << myList.front()
		<< ", back(): " << myList.back()
		<< ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList) {
	theList.front() = 17;
	theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
	for (size_t i = 0; i < myList.size(); ++i) {
		cout << myList[i] << ' ';
	}
	cout << endl;
}

// Task 8
void doNothing(List aList) {
	cout << "In doNothing\n";
	printListInfo(aList);
	cout << endl;
	cout << "Leaving doNothing\n";
}

int main() {

	// Task 1
	cout << "\n------Task One------\n";
	List myList;
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList.push_back(" << i * i << ");\n";
		myList.push_back(i * i);
		printListInfo(myList);
	}
	cout << "===================\n";

	cout << "Modify the first and last items, and display the results\n";
	changeFrontAndBack(myList);
	printListInfo(myList);
	cout << "===================\n";

	cout << "Remove the items with pop_back\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_back();
	}
	cout << "===================\n";

	// Task 2
	cout << "\n------Task Two------\n";
	cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList2.push_front(" << i * i << ");\n";
		myList.push_front(i * i);
		printListInfo(myList);
	}
	cout << "===================\n";
	cout << "Remove the items with pop_front\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_front();
	}
	cout << "===================\n";

	// Task 3
	cout << "\n------Task Three------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		myList.push_back(i * i);
	}
	printListInfo(myList);
	cout << "Now clear\n";
	myList.clear();
	cout << "Size: " << myList.size() << ", list: " << myList << endl;
	cout << "===================\n";

	// Task 4
	cout << "\n------Task Four------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
	cout << "Display elements with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;
	cout << "Add one to each element with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
	cout << "And print it out again with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;
	cout << "Now calling a function, printListSlow, to do the same thing\n";
	printListSlow(myList);
	cout << "Finally, for this task, using the index operator to modify\n"
		<< "the data in the third item in the list\n"
		<< "and then using printListSlow to display it again\n";
	myList[2] = 42;
	printListSlow(myList);


	// Task 5
	cout << "\n------Task Five------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
	printListInfo(myList);
	cout << "Now display the elements in a ranged for\n";
	for (int x : myList) cout << x << ' ';
	cout << endl;
	cout << "And again using the iterator type directly:\n";
	// Note you can choose to nest the iterator class or not, your choice.
	//for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
	for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	cout << "WOW!!! (I thought it was cool.)\n";

	// Task 6
	cout << "\n------Task Six------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	printListInfo(myList);
	cout << "Filling an empty list with insert at begin(): "
		<< "i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i * i);
	printListInfo(myList);
	// ***Need test for insert other than begin/end***
	cout << "===================\n";

	// Task 7
	cout << "\n------Task Seven------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	cout << "Erasing the elements in the list, starting from the beginning\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.erase(myList.begin());
	}
	// ***Need test for erase other than begin/end***
	cout << "===================\n";

	// Task 8
	cout << "\n------Task Eight------\n";
	cout << "Copy control\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	printListInfo(myList);
	cout << "Calling doNothing(myList)\n";
	doNothing(myList);
	cout << "Back from doNothing(myList)\n";
	printListInfo(myList);

	cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
	List listTwo;
	for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i * i);
	printListInfo(listTwo);
	cout << "listTwo = myList\n";
	listTwo = myList;
	cout << "myList: ";
	printListInfo(myList);
	cout << "listTwo: ";
	printListInfo(listTwo);
	cout << "===================\n";
}
