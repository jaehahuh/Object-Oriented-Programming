//Author: Jaeha Huh
//Name of File: rec10.cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Instrument {
public:
	Instrument() {}
	virtual void makeSound() const = 0;
	virtual void play() const = 0;
private:
};

void Instrument::makeSound() const { cout << "To make a sound..."; }



class Brass : public Instrument {
public:
	Brass(unsigned mouthpiece) :
		Instrument(), mouthpiece(mouthpiece) {}
	virtual void makeSound() const = 0;
private:
	unsigned mouthpiece;
};


void Brass::makeSound() const {
	Instrument::makeSound();
	cout << " blow on a mouthpiece of size " << mouthpiece << endl;
}


class BrassIn : public Brass {
public:
	BrassIn(unsigned mouthpiece) : Brass(mouthpiece) {}
	virtual void makeSound() const {
		Brass::makeSound();
	}
private:
protected:
};


class Trumpet : public Brass {
public:
	Trumpet(unsigned mouthpiece) : Brass(mouthpiece) {}
	virtual void makeSound() const {
		Brass::makeSound();
	}
	void play() const { cout << "Toot"; }
private:
protected:
};

class Trombone : public Brass {
public:
	Trombone(unsigned mouthpiece) : Brass(mouthpiece) {}
	virtual void makeSound() const {
		Brass::makeSound();
	}
	void play()const { cout << "Blat"; }
private:
protected:
};



class String : public Instrument {
public:
	String(unsigned pitch) : Instrument(), pitch(pitch) {}
	virtual void makeSound() const = 0;
private:
	unsigned pitch;
protected:
};

void String::makeSound() const {
	Instrument::makeSound();
	cout << " bow a string with pitch " << pitch << endl;
}


class Violin : public String {
public:
	Violin(unsigned pitch) : String(pitch) {}
	virtual void makeSound() const {

		String::makeSound();
	}
	void play()const { cout << "Screech"; }
private:
protected:
};


class Cello : public String {
public:
	Cello(unsigned pitch) : String(pitch) {}
	virtual void makeSound() const {

		String::makeSound();
	}
	void play()const { cout << "Squawk"; }
private:
protected:
};





class Percussion : public Instrument {
public:
	Percussion() : Instrument() {}
	virtual void makeSound() const = 0;
private:
protected:
};

void Percussion::makeSound() const {
	Instrument::makeSound();
	cout << " hit me! " << endl;
}

class Drum : public Percussion {
public:
	Drum() : Percussion() {}
	virtual void makeSound() const {

		Percussion::makeSound();
	}
	void play()const { cout << "Boom"; }
private:
protected:
};

class Cymbal : public Percussion {
public:
	Cymbal() : Percussion() {}
	virtual void makeSound() const {

		Percussion::makeSound();
	}
	void play() const { cout << "Crash"; }
private:
protected:
};




class Musician {
public:
	Musician() : instr(nullptr) {}

	void acceptInstr(Instrument* instPtr) { instr = instPtr; }

	Instrument* giveBackInstr() {
		Instrument* result(instr);
		instr = nullptr;
		return result;
	}
	void normalPlay() const {
		if (instr) instr->play();
	}
	void testPlay() const {
		if (instr) instr->makeSound();
		else cerr << "have no instr\n";
	}

private:
	Instrument* instr;
};

class MILL {
public:
	MILL() {}
	void receiveInstr(Instrument& anIns) {
		bool foundSpace = false;
		for (size_t i = 0; i < ins.size(); ++i) {
			if (ins[i] == nullptr) {
				ins[i] = &anIns;
				foundSpace = true;
				break;
			}
		}
		if (foundSpace == false) {
			ins.push_back(&anIns);
		}
	}
	void dailyTestPlay() const {
		for (const Instrument* anIns : ins) {
			if (anIns != nullptr) {
				anIns->makeSound();
			}
		}
	}
	Instrument* loanOut() {
		for (size_t i = 0; i < ins.size(); ++i) {
			if (ins[i] != nullptr) {
				Instrument* temp = ins[i];
				ins[i] = nullptr;
				return temp;
			}
		}
		return nullptr;
	}
private:
	vector<Instrument*> ins;
};

class Orch {
public:
	void addPlayer(Musician& aMus) {
		mus.push_back(&aMus);
	}
	void play() {
		for (size_t i = 0; i < mus.size(); ++i) {
			mus[i]->normalPlay();
		}
	}
private:
	vector<Musician*> mus;
};

//// PART ONE
//int main() {
//
//	cout << "Define some instruments ------------------------------------\n";
//	Drum drum;
//	Cello cello(673);
//	Cymbal cymbal;
//	Trombone tbone(4);
//	Trumpet trpt(12);
//	Violin violin(567);
//
//	//      use the debugger to look at the mill
//	cout << "Define the MILL --------------------------------------------\n";
//	MILL mill;
//
//	cout << "Put the instruments into the MILL --------------------------\n";
//	mill.receiveInstr(trpt);
//	mill.receiveInstr(violin);
//	mill.receiveInstr(tbone);
//	mill.receiveInstr(drum);
//	mill.receiveInstr(cello);
//	mill.receiveInstr(cymbal);
//
//	cout << "Daily test -------------------------------------------------\n";
//	cout << endl;
//	cout << "dailyTestPlay()" << endl;
//	mill.dailyTestPlay();
//	cout << endl;
//
//	cout << "Define some Musicians---------------------------------------\n";
//	Musician harpo;
//	Musician groucho;
//
//	cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//	groucho.testPlay();
//	cout << endl;
//	groucho.acceptInstr(mill.loanOut());
//	cout << endl;
//	groucho.testPlay();
//	cout << endl;
//	cout << "dailyTestPlay()" << endl;
//	mill.dailyTestPlay();
//
//	cout << endl << endl;
//
//	groucho.testPlay();
//	cout << endl;
//	mill.receiveInstr(*groucho.giveBackInstr());
//	harpo.acceptInstr(mill.loanOut());
//	groucho.acceptInstr(mill.loanOut());
//	cout << endl;
//	groucho.testPlay();
//	cout << endl;
//	harpo.testPlay();
//	cout << endl;
//	cout << "dailyTestPlay()" << endl;
//	mill.dailyTestPlay();
//
//	cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//	// fifth
//	mill.receiveInstr(*groucho.giveBackInstr());
//	cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//	mill.receiveInstr(*harpo.giveBackInstr());
//
//
//	cout << endl;
//	cout << "dailyTestPlay()" << endl;
//	mill.dailyTestPlay();
//	cout << endl;
//
//	cout << endl;
//}
//


// PART TWO
int main() {
	// The initialization phase

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

} // main






