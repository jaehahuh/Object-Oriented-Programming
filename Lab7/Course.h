#ifndef Course_h
#define Course_h

#include <string>
#include <vector>


namespace BrooklynPoly {

	class Student;


	class Course {
		friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
	public:
		Course(const std::string& courseName);
		std::string getName() const;
		void addStudent(Student*& aStudent);
		void purge();
	private:
		size_t findStudent(const Student* aStudent) const;
		std::string name;
		std::vector<Student*> students;
	};
}

#endif