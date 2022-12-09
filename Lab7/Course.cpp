#include "Course.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

//***class Course***//

namespace BrooklynPoly {

	ostream& operator<< (ostream& os, const Course& rhs) {
		os << rhs.name << ": ";
		if (rhs.students.size() != 0) {
			for (const Student* aStudent : rhs.students) {
				os << aStudent->getName() << "  ";
			}
		}
		else { os << "No Students"; }
		return os;
	}
	Course::Course(const string& courseName) : name(courseName) {}
	string Course::getName() const { return name; }
	void Course::addStudent(Student*& aStudent) {
		if (findStudent(aStudent) == students.size()) {
			//make sure no repeated adding
			students.push_back(aStudent);
		}
	}
	void Course::purge() {
		while (students.size() != 0) {
			students[students.size() - 1]->courseIsCancelled(this);
			students[students.size() - 1] = nullptr;
			students.pop_back();
		}
	}
	size_t Course::findStudent(const Student* aStudent) const {
		//find student index
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i] == aStudent) {
				return i;
			}
		}
		return students.size();
		//return student.size() if the student can't be found
	}

}
