#include "Registrar.h"
#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

namespace BrooklynPoly {

	ostream& operator<< (ostream& os, const Registrar& rhs) {
		os << "Registrar's report" << endl;
		os << "Courses: " << endl;
		for (const Course* aCourse : rhs.courses) { os << *aCourse << endl;; }
		os << "Students: " << endl;
		for (const Student* aStudent : rhs.students) { os << *aStudent << endl;; }
		return os;
	}
	Registrar::Registrar() {};
	bool Registrar::addCourse(const string& courseName) {
		if (findCourse(courseName) != courses.size()) {
			//if it has been added
			cout << "The course has already been added" << endl;
			return false;
		}
		else {
			courses.push_back(new Course(courseName));
			return true;
		}
	}
	bool Registrar::addStudent(const string& studentName) {
		if (findStudent(studentName) != students.size()) {
			cout << "This student has already been added" << endl;
			return false;
		}
		else {
			students.push_back(new Student(studentName));
			return true;
		}
	}
	bool Registrar::enrollStudentInCourse
	(const string& studentName, const string& courseName) {
		//connecting student<<-->>course
		size_t studentIndex = findStudent(studentName);
		size_t courseIndex = findCourse(courseName);
		if (studentIndex == students.size()
			|| courseIndex == courses.size()) {
			cout << "Either student ot course does not exist" << endl;
			return false;
		}
		else {
			students[studentIndex]->addCourse(courses[courseIndex]);
			courses[courseIndex]->addStudent(students[studentIndex]);
			return true;
		}
	}
	bool Registrar::cancelCourse(const string& courseName) {
		size_t cancelled = findCourse(courseName);
		//size_t cancelled means cancelled_course_index
		if (cancelled != courses.size()) {
			//if it can be found

			courses[cancelled]->purge();
			//clean it up

			courses[cancelled] = nullptr;
			delete courses[cancelled];
			Course* temp;
			for (size_t i = cancelled; cancelled < courses.size() - 1; ++cancelled) {
				temp = courses[i];
				courses[i] = courses[i + 1];
				courses[i + 1] = temp;
			}
			courses.pop_back();
			return true;
		}
		else {
			cout << "The course doesn't exist" << endl;
			return false;
		}
	}
	void Registrar::purge() {
		while (courses.size() != 0) {
			courses[courses.size() - 1]->purge();
			delete courses[courses.size()-1];
			courses.pop_back();
		}
		while (students.size() != 0) {
			delete students[students.size() - 1];
			students.pop_back();
		}
	}
	size_t Registrar::findStudent(const string& studentName) const {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studentName) {
				return i;
			}
		}
		return students.size();
	}
	size_t Registrar::findCourse(const string& courseName) const {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return i;
			}
		}
		return courses.size();
	}

}
