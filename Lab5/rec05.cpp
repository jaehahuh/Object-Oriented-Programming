//Author: Jaeha Huh
//File name: rec05.cpp
//Description: build Lab class by using heap memory.


#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Section {
	friend ostream& operator << (ostream& os, const Section& section);
public:
	Section(const string& name, const string& day, int time) 
		: secName(name), times(day, time), studentList(0)  {}

	void addStudent(const string& name) {
		StudentRecord* student = new StudentRecord(name);
		studentList.push_back(student);
	}
	
	void addGrade(const string& name, int grade, int week) {
		for (size_t i = 0; i < studentList.size(); i++){
			if (name == studentList[i]->getName()) {
				studentList[i]->addGrade(grade, week);
				break;
			}
		}
	}

	void deleteList() {
		cout << "Section " << secName << " is being deleted." << endl;
		for (size_t i = 0; i < studentList.size(); i++) {
			cout << "Deleting " << studentList[i]->getName() << endl;
			delete studentList[i];
			studentList[i] = NULL;
		}
		studentList.clear();
	}
	
	class Timeslot {
		friend ostream& operator<<(ostream& os, const Timeslot& rhs) {
			if (rhs.time > 12) {
				cout << (rhs.time - 12) << "PM" << endl;
			}
			else {
				cout << rhs.time << "AM" << endl;
			}
			os << "[Day: " << rhs.date << ",Start time:" << rhs.time << "]" << endl;
			return os;
		}
		
	public:
		Timeslot(const string& day, int time) : date(day), time(time) {}
		
	private:
		string date;
		int time;
	};

	class StudentRecord {
		friend ostream& operator<<(ostream& os, const StudentRecord& student) {
			os << "Name: " << student.stuName << ", Grades: ";
			for (size_t i = 0; i < student.grade.size(); i++) {
				os << student.grade[i];
			}
			return os;
		}

	public:
		StudentRecord(const string& name) :stuName(name), grade(14, -1){}
		string getName() {return stuName;}
		void addGrade(int grad, int week) {
			grade[week-1] = grad;
		}

	private:
		string stuName;
		vector<int> grade;
	};

private:
	string secName;
	Timeslot times;
	vector<StudentRecord*> studentList;
	
};

class LabWorker {
	friend ostream& operator << (ostream& os, const LabWorker& worker){
		if (worker.section == nullptr) {
			os << worker.name << " does not have a section." << endl;
		}
		else {
			os << worker.name << " has " << *(worker.section) << endl;
		}
		return os;
	}
public:
	LabWorker(const string& name) : name(name), section(nullptr) {}
	void addSection(Section& sec) {
		this->section = &sec;
	}
	void addGrade(const string& name, int grade, int week){
		section->addGrade(name, grade, week);
	}

private:
	string name;
	Section* section;
};

ostream& operator << (ostream& os, const Section& section) {
	os << "Section: " << section.secName << " Time slot: " << section.times << ", Students: ";
	if (section.studentList.size() == 0) {
		os << "None";
	}
	else {
		for (size_t i = 0; i < section.studentList.size(); i++) {
			os << *(section.studentList[i]) << endl;
		}
	}
	return os;
}

// Test code
void doNothing(Section sec) { cout << sec << endl; }


int main() {

	cout << "Test 1: Defining a section\n";
	Section secA2("A2", "Tuesday", 16);
	cout << secA2 << endl;

	cout << "\nTest 2: Adding students to a section\n";
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");
	cout << secA2 << endl;

	cout << "\nTest 3: Defining a lab worker.\n";
	LabWorker moe("Moe");
	cout << moe << endl;

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	moe.addSection(secA2);
	cout << moe << endl;

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	LabWorker jane("Jane");
	Section secB3("B3", "Thursday", 11);
	secB3.addStudent("thorin");
	secB3.addStudent("dwalin");
	secB3.addStudent("balin");
	secB3.addStudent("kili");
	secB3.addStudent("fili");
	secB3.addStudent("dori");
	secB3.addStudent("nori");
	secB3.addStudent("ori");
	secB3.addStudent("oin");
	secB3.addStudent("gloin");
	secB3.addStudent("bifur");
	secB3.addStudent("bofur");
	secB3.addStudent("bombur");
	jane.addSection(secB3);
	cout << jane << endl;

	cout << "\nTest 6: Adding some grades for week one\n";
	moe.addGrade("John", 17, 1);
	moe.addGrade("Paul", 19, 1);
	moe.addGrade("George", 16, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << moe << endl;

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	moe.addGrade("John", 15, 3);
	moe.addGrade("Paul", 20, 3);
	moe.addGrade("Ringo", 0, 3);
	moe.addGrade("George", 16, 3);
	cout << moe << endl;

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
		<< "those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
		<< "then make sure the following call works:\n";

	secA2.deleteList();

	doNothing(secA2);
	cout << "Back from doNothing\n\n";

	secB3.deleteList();



} // main