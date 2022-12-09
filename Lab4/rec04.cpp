//Author : Jaeha Huh
//Name of File : rec04.cpp
//Description : Pointer Tutorial

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Complex {
	double real;
	double img;
};

class PlainOldClass {
public:
	PlainOldClass() : x(-72) {}
	int getX() const { return x; }
	void setX(int val) { x = val; }
private:
	int x;
};

class PlainOldClassV2 {
public:
	PlainOldClassV2() : x(-72) {}
	int getX() const { return x; }
	void setX(int x) { this->x = x; }
private:
	int x;
};

class Colour {
public:
	Colour(const string& name, unsigned r, unsigned g, unsigned b)
		: name(name), r(r), g(g), b(b) {}
	void display() const {
		cout << name << " (RBG: " << r << "," << g << "," << b << ")";
	}
private:
	string name;      // what we call this colour       
	unsigned r, g, b; // red/green/blue values for displaying  
};


class SpeakerSystem {
public:
	void vibrateSpeakerCones(unsigned signal) const {

		cout << "Playing: " << signal << "Hz sound..." << endl;
		cout << "Buzz, buzzy, buzzer, bzap!!!\n";
	}
};

class Amplifier {
public:
	void attachSpeakers(const SpeakerSystem& spkrs)
	{
		if (attachedSpeakers)
			cout << "already have speakers attached!\n";
		else
			attachedSpeakers = &spkrs;
	}

	void detachSpeakers() { // should there be an "error" message if not attached?
		attachedSpeakers = nullptr;
	}

	void playMusic() const {
		if (attachedSpeakers)
			attachedSpeakers->vibrateSpeakerCones(440);
		else
			cout << "No speakers attached\n";
	}
private:
	const SpeakerSystem* attachedSpeakers = nullptr;
};


class Person {
public:
	Person(const string& name) : name(name) {}
	void movesInWith(Person& newRoomate) {
		if (&newRoomate != this && &newRoomate.roomie == nullptr && roomie == nullptr ) {
			//if you don't have a roommate, if your new roommate doesn't have a rommate, if your new roommate is not yourself
			roomie = &newRoomate;        // now I have a new roomie            
			newRoomate.roomie = this;    // and now they do too
		
		}
		else {
			cerr << "There is an error" << endl;
		}
			     
	}
	const string& getName() const { return name; }
	// Don't need to use getName() below, just there for you to use in debugging.
	const string& getRoomiesName() const { return roomie->getName(); }
private:
	Person* roomie;
	string name;
};




int main() {
	int x;
	x = 10;
	cout << "x = " << x << endl;
	cout << "address of x is " << &x << endl;
	// cout << oct << 0xB << endl;

	int* p;
	//p = 0x00cffd14;
	p = &x;
	cout << "p = " << p << endl;
	cout << "p points to where " << *p << " is stored\n";
	cout << "*p contains " << *p << endl;


	*p = -2763;
	cout << "p points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	cout << "x now contains " << x << endl;


	int y(13);
	cout << "y contains " << y << endl;
	p = &y;
	cout << "p now points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	*p = 980;
	cout << "p points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	cout << "y now contains " << y << endl;

	int* q;
	q = p;
	cout << "q points to where " << *q << " is stored\n";
	cout << "*q contains " << *q << endl;

	double d(33.44);
	double* pD(&d);
	*pD = *p;
	*pD = 73.2343;
	*p = *pD;
	*q = *p;
	//pD = p;    p is int* p;
	//p = pD;


	int joe = 24;
	const int sal = 19;
	int* pI;
	pI = &joe;
	*pI = 234;
	//pI = &sal;  
	*pI = 7623;

	const int* pcI;
	pcI = &joe;
	//*pcI = 234;  
	pcI = &sal;
	//*pcI = 7623;    

	//int* const cpI;
	int* const cpI(&joe);
	//int* const cpI(&sal);
	//cpI = &joe;  
	*cpI = 234;
	//cpI = &sal;  
	*cpI = 7623;

	//const int* const cpcI;
	const int* const cpcI(&joe);
	//const int* const cpcI(&sal);
	//cpcI = &joe;  
	//*cpcI = 234;  
	//cpcI = &sal;  
	//*cpcI = 7623;  

	//TYPE* variableName; // can hold a pointer to TYPE value

	Complex c = { 11.23,45.67 };
	Complex* pC(&c);


	//cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
	cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
	cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;




	PlainOldClass poc;
	PlainOldClass* ppoc(&poc);
	cout << ppoc->getX() << endl;
	ppoc->setX(2837);
	cout << ppoc->getX() << endl;


	PlainOldClassV2 poc2;
	PlainOldClassV2* ppoc2(&poc2);
	cout << ppoc2->getX() << endl;
	ppoc2->setX(2837);
	cout << ppoc2->getX() << endl;

	int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
	*pDyn = 17;

	cout << "The " << *pDyn
		<< " is stored at address " << pDyn
		<< " which is in the heap\n";

	cout << pDyn << endl;
	delete pDyn;
	//cout << pDyn << endl;

	//cout << "The 17 might STILL be stored at address " << pDyn << " even though we deleted pDyn\n";
	//cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";

	pDyn = nullptr;
	double* pDouble = nullptr;
	cout << pDyn << endl;

	double* pTest = new double(12);
	delete pTest;
	pTest = nullptr;
	delete pTest; // safe

	short* pShrt = new short(5);
	delete pShrt;
	//delete pShrt;

	//No, delete can only be used with the heap (also known as dynamic memory or free store).
	/*
	long jumper = 12238743;
	delete jumper;
	long* ptrTolong = &jumper;
	delete ptrTolong;
	Complex cmplx;
	delete cmplx;
	*/

	vector<Complex*> complV; // can hold pointers to Complex objects
	Complex* tmpPCmplx;      // space for a Complex pointer
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		tmpPCmplx = new Complex; // create a new Complex object on the heap
		tmpPCmplx->real = ndx;   // set real and img to be the
		tmpPCmplx->img = ndx;   // value of the current ndx
		complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
	}
	// display the objects using the pointers stored in the vector
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		cout << complV[ndx]->real << endl;
		cout << complV[ndx]->img << endl;
	}
	// release the heap space pointed at by the pointers in the vector      
	for (size_t ndx = 0; ndx < 3; ++ndx) {
		delete complV[ndx];
	}
	// clear the vector      
	complV.clear();

	
	vector<Colour*> colours;
	string inputName;
	unsigned inputR, inputG, inputB;

	
	while (cin >> inputName >> inputR >> inputG >> inputB) {
		colours.push_back(new Colour(inputName, inputR, inputG, inputB));
	}

	// display all the Colours in the vector:       
	for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
		colours[ndx]->display();
		delete colours[ndx];
		cout << endl;
	}
	colours.clear();

	// write code to model two people in this world       
	Person joeBob("Joe Bob"), billyJane("Billy Jane");

	// now model these two becoming roommates       
	joeBob.movesInWith(billyJane);

	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;


}