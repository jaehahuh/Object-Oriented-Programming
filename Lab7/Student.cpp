
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

//***class Student***//

namespace BrooklynPoly {

	ostream& operator<< (ostream& os, const Student& rhs) {
		os << rhs.name << ": ";
		if (rhs.courses.size() != 0) {
			for (const Course* aCourse : rhs.courses) {
				os << aCourse->getName() << "   ";
			}
		}
		else { os << "No Courses"; }
		return os;
	}
	Student::Student(const string& name) : name(name) {}
	string Student::getName() const { return name; }
	void Student::addCourse(Course*& aCourse) {
		if (findCourse(aCourse) == courses.size()) {
			//if the course hasn't been added
			courses.push_back(aCourse);
		}
	}
	void Student::courseIsCancelled(Course* cancelledCourse) {
		//a student drops a course
		size_t cancelledCourseIndex = findCourse(cancelledCourse);
		courses[cancelledCourseIndex] = nullptr;
		Course* temp;
		for (size_t i = cancelledCourseIndex; i < courses.size() - 1; ++i) {
			temp = courses[i];
			courses[i] = courses[i + 1];
			courses[i + 1] = temp;
		}
		courses.pop_back();
	}
	size_t Student::findCourse(const Course* aCourse) const {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (&courses[i] == &aCourse) {
				return i;
			}
		}
		return courses.size();
		//return the size if cannot find it
	}

}
