//Author : Jaeha Huh
//File of Name: polynomial.cpp

#include "polynomial.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


Polynomial::Node::Node(int data, Node* prev, Node* next) : data(data), prev(prev), next(next) {}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
	if (lhs.degree != rhs.degree) { // check degree
		return false;
	}
	Polynomial::Node* lhsIndex = lhs.head->next;
	Polynomial::Node* rhsIndex = rhs.head->next;
	while (lhsIndex->next) { // check data
		if (lhsIndex->data != rhsIndex->data) {
			return false;
		}
		lhsIndex = lhsIndex->next;
		rhsIndex = rhsIndex->next;
	}
	return true;
}

ostream& operator<<(ostream& os, const Polynomial& rhs) {
	Polynomial::Node* ind = rhs.tail->prev;
	size_t power = rhs.degree;

	while (ind->prev) { //while it's not head node

		int coefficient = ind->data;

		if (rhs.degree == 0 && coefficient == 0) { // check for zero polynomial
			os << "0";
		}
		else {
			if (coefficient < 0) { //negative coef: will print a minus dign
				os << " - ";
				if (coefficient == -1) {
					if (power == 0) {
						os << -coefficient; // -1
					}
					else if (power == 1) {
						os << "x";
					}
					else { // coef = -1 and has a power other than 0 or 1
						os << "x^" << power;
					}
				}
				else { // coef < 0 and != -1
					if (power == 0) {
						os << -coefficient;
					}
					else if (power == 1) {
						os << -coefficient << "x";
					}
					else {
						os << -coefficient << "x^" << power;
					}
				}
			}
			else { // coef > or = 0: will possibly print a plus sign
				if (power != rhs.degree && coefficient != 0) {
					//if this isn't the higest power term && not zero
					os << " + ";
				}
				if (coefficient == 1) {
					if (power == 0) {
						os << coefficient;
					}
					else if (power == 1) {
						os << "x";
					}
					else {
						os << "x^" << power;
					}
				}
				else if (coefficient != 0) {
					if (power == 0) {
						os << coefficient;
					}
					else if (power == 1) {
						os << coefficient << "x";
					}
					else {
						os << coefficient << "x^" << power;
					}
				}
			}
		}
		ind = ind->prev;
		--power;
	}
	return os;
}

Polynomial::Polynomial(const vector<int>& coe) : degree(-1), head(new Node), tail(new Node) {
	head->next = tail;
	tail->prev = head;
	if (coe[0] == 0) { //if it's zero polynomial
		push_back(0); //degree = (-1) + 1 = 0
	}
	else {
		for (size_t i = coe.size() - 1; i < -1; --i) {
			push_back(coe[i]);//will increment the value of degree
		}
	}
}

void Polynomial::push_back(int data) {
	Node* node = new Node(data, tail->prev, tail);
	tail->prev->next = node;
	tail->prev = node;
	++degree;
}

void Polynomial::pop_back() {
	Node* ind = tail->prev;
	ind->prev->next = tail;
	tail->prev = ind->prev;
	delete ind;
	--degree;
}

//copy constructor;
Polynomial::Polynomial(const Polynomial& rhs) : degree(-1), head(new Node), tail(new Node) {
	head->next = tail;
	tail->prev = head;
	Node* ind = rhs.head->next;
	while (ind->next) {
		push_back(ind->data); //will increment the value of degree
		ind = ind->next;
	}
}

Polynomial::~Polynomial() {
	while (head->next != tail) {
		pop_back(); //will delete node and decrement degree
	}
	delete head;
	delete tail;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (&rhs != this) {
		while (head->next != tail) {//
			pop_back();
		}
		Node* rhsInd = rhs.head->next;
		while (rhsInd->next) {
			push_back(rhsInd->data);
			rhsInd = rhsInd->next;
		}
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	if (degree < rhs.degree) { //self degree < rhs degree
		Node* rhsIndex = rhs.head->next;
		Node* selfIndex = head->next;
		for (size_t i = 0; i < degree + 1; ++i) {
			selfIndex->data += rhsIndex->data;
			selfIndex = selfIndex->next;
			rhsIndex = rhsIndex->next;
		}
		while (rhsIndex->next) {//add the rest of high power term(s)
			push_back(rhsIndex->data);
			rhsIndex = rhsIndex->next;
		}
	}
	else if (degree > rhs.degree) { // self degree > rhs degree
		Node* rhsIndex = rhs.head->next;
		Node* selfIndex = head->next;
		for (size_t i = 0; i < rhs.degree + 1; ++i) {
			selfIndex->data += rhsIndex->data;
			selfIndex = selfIndex->next;
			rhsIndex = rhsIndex->next;
		}
	}
	else { //same degree
		Node* selfIndex = head->next;
		Node* rhsIndex = rhs.head->next;
		while (selfIndex->next) {
			selfIndex->data += rhsIndex->data;
			selfIndex = selfIndex->next;
			rhsIndex = rhsIndex->next;
		}
	}
	clearZeros();//make sure high power term(s) isn't zero if it's not a zero polynomial
	return *this;
}

void Polynomial::clearZeros() {

	//clear non-zero polynomial with zero(s) in the high degree term(s) after two polynimials are added
	Node* ind = tail->prev;
	while (ind->prev != head && ind->data == 0) {
		//stop when it reaches the (head->next) node to make sure the polynomial has at least one term (zero polynomial degree = 0, length = 1);
		//or stop when it meets a non-zero term
		Node* temp = ind;
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		--degree;
		ind = ind->prev;
	}
}

int Polynomial::evaluate(int n) const {
	Node* ind = head->next;
	size_t power = 0;
	int result = 0;
	while (ind->next) {
		result += (ind->data) * pow(n, power);
		ind = ind->next;
		++power;
	}
	return result;
}



Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial result(lhs);
	result += rhs;
	return result;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
	return !(lhs == rhs);
}



void doNothing(Polynomial temp) {}



int main() {

	//test constructor
	Polynomial p1({ 17 });                 // 17
	Polynomial p2({ 1, 2 });               // x + 2
	Polynomial p3({ -1, 5 });              // -1x + 5
	Polynomial p4({ 5, 4, 3, 2, 1 });      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
	Polynomial has_a_zero({ 4, 0, 1, 7 }); // 4x^3 + x + 7

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	cout << "p4: " << p4 << endl;
	cout << "has_a_zero: " << has_a_zero << endl;
	cout << "p2 + p3: " << (p2 + p3) << endl;
	cout << "p2 + p4: " << (p2 + p4) << endl;
	cout << "p4 + p2: " << (p4 + p2) << endl;


	//test copy constructor - the statement below uses the copy constructor
	//to initialize poly3 with the same values as poly4
	Polynomial p5(p4);
	p5 += p3;
	cout << "Polynomial p5(p4);\n"
		<< "p5 += p3;\n";

	cout << "p4: " << p4 << endl;
	cout << "p5: " << p5 << endl;

	cout << "Calling doNothing(p5)\n";
	doNothing(p5);
	cout << "p5: " << p5 << endl;

	//tests the assignment operator
	Polynomial p6;
	cout << "p6: " << p6 << endl;
	cout << boolalpha;  // Causes bools true and false to be printed that way.
	cout << "(p4 == p6) is " << (p4 == p6) << endl;
	p6 = p4;
	cout << "p6: " << p6 << endl;
	cout << boolalpha;
	cout << "(p4 == p6) is " << (p4 == p6) << endl;

	//test the evaluaton
	int x = 5;
	cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
	cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;

	Polynomial p7({ 3, 2, 1 });           // 3x^2 + 2x + 1
	cout << "p7: " << p7 << endl;
	cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

	cout << boolalpha;
	cout << "(p1 == p2) is " << (p1 == p2) << endl;
	cout << "(p1 != p2) is " << (p1 != p2) << endl;

	/*=================================================================
	NEW TEST CODE - test if cleaning the leading 0s
	===================================================================*/

	Polynomial p8({ 1, 1 });
	Polynomial p9({ -1, 1 });
	Polynomial p10({ 0, 0, 2 });
	//p8 + p9 tests if += does the cleanup()
	//p10 tests if constructor does the cleanup()
	cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;


}