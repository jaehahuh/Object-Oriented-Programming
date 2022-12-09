#ifndef Student_h
#define Student_h

#include "Course.h"
#include <string>
#include <vector>

namespace BrooklynPoly {
	class Student {
		friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
	public:
		Student(const std::string& name);
		std::string getName() const;
		void addCourse(Course*& aCourse);
		void courseIsCancelled(Course* aCourse);
	private:
		size_t findCourse(const Course* aCourse) const;
		std::string name;
		std::vector<Course*> courses;
	};
}


#endif 
