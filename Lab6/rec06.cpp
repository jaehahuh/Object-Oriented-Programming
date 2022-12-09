//Author : Jaeha Huh
//Name of File: rec06.cpp
//Descrption : copy control and destructor


#include <string>
#include <iostream>
using namespace std;

class Position {
	friend ostream& operator<<(ostream& os, const Position& rhs) {
		os << '[' << rhs.title << ',' << rhs.salary << ']';
		return os;
	}
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	const string& getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
private:
	string title;
	double salary;
}; // class Position

class Entry {
	friend ostream& operator<<(ostream& os, const Entry& rhs) {
		os << rhs.name << ' ' << rhs.room
			<< ' ' << rhs.phone << ", " << *rhs.pos;
		return os;
	}
public:
	Entry(const string& name, unsigned room, unsigned phone, Position& position)
		: name(name), room(room), phone(phone), pos(&position) {
	}
	const string& getName() const { return name; }
	unsigned getPhone() const { return phone; }
	
private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
	// Overload output operator
	friend ostream& operator << (ostream& os, const Directory& rhs) {
		os << "Size: " << rhs.size << " ,capacity: " << rhs.capacity << endl;
		for (size_t i = 0; i < rhs.size; ++i) {
			os << *rhs.entries[i] << endl;
		}
		return os;
	}
public:
	// Of course the first function you need to write for this (or
	// any) class is...
	// ???
	// ...

	Directory() : size(0), capacity(4), entries(new Entry* [4]) { 
		cout << "constructor" << endl; 
	}
	unsigned operator[](const string& name) const { //overwrite the bracket operator
		cout << "overwrite [] operator" << endl;
		for (size_t i = 0; i < size; ++i) {
			if (entries[i]->getName() == name) {
				return entries[i]->getPhone();
			}
		}
		return 0;
	}
	~Directory() { //destructor
		cout << "destructor" << endl;
		for (size_t i = 0; i < size; ++i) {
			delete entries[i];
		}
		delete[] entries;
	}
	Directory(const Directory& rhs) : size(rhs.size), capacity(rhs.capacity), entries(new Entry* [rhs.capacity]) { //copy constructor
		cout << "copy constructor" << endl;
		for (size_t i = 0; i < rhs.size; ++i) {
			entries[i] = new Entry(*(rhs.entries[i]));
		}
	}
	Directory& operator=(const Directory& rhs) { //assignment operator
		cout << "=operator" << endl;
		if (this != &rhs) {
			for (size_t i = 0; i < size; ++i) { //delete every pointer in array
				delete entries[i];
			}
			delete[] entries; //delete the array
			entries = new Entry * [rhs.capacity];
			size = rhs.size;
			capacity = rhs.capacity;
			for (size_t i = 0; i < size; ++i) {
				entries[i] = new Entry(*(rhs.entries[i]));
			}
		}
		return *this;
	}
	// We'll get you started with the add method, but obviously you
	// have a lot of work to do here.
	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (size == capacity) {
			Entry** old = entries;
			entries = new Entry*[2*capacity];
			for (size_t i = 0; i < size; ++i) { //copy every pointer over to new array
				entries[i] = old[i];
			}
			delete[] old; //delete old array
			capacity *= 2;// something is missing!!!  Add it!

		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

private:
	
	Entry** entries;
	size_t size;
	size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

	// Note that the Postion objects are NOT on the heap.
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	cout << d << endl;

	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	cout << d << endl;

	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;

	// Should display 1592
	cout << d2["Carmack"] << endl;

} // main
