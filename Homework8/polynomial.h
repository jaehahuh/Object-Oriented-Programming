//Author : Jaeha Huh
//File of Name: polynomial.h

#ifndef Polynomial_H
#define Polynomial_H

#include <vector>
#include <string>
#include <iostream>


class Polynomial {

	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);

public:

	Polynomial(const std::vector<int>& coe = { 0 });

	void push_back(int data);

	void pop_back();

	Polynomial(const Polynomial& rhs);

	~Polynomial();

	Polynomial& operator=(const Polynomial& rhs);

	Polynomial& operator+=(const Polynomial& rhs);

	void clearZeros();

	int evaluate(int n)const;

private:
	struct Node {
		Node(int data = 0, Node * prev = nullptr, Node * next = nullptr);
		//        void print(int a);
		int data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;
	size_t degree; // degree = size - 1;
};


Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

void doNothing(Polynomial temp);


#endif //polynomial.h
