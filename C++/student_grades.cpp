/*
	student_grades.cpp

	This program asks for an array of students
	name and grade and then sorts them according
	to increasing grade.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct Student
{
	std::string name {};
	int grade {};
};

std::vector<Student> input()
{
	int n {};
	std::cout << "Enter number of students: ";
	std::cin >> n;

	std::vector<Student> students(n);

	for (auto& student : students)
	{
		std::cout << "Enter name of student: ";
		std::cin >> student.name;

		int grade {};
		do
		{
			std::cout << "Enter grade of student (0-100): ";
			std::cin >> grade;

			if (grade < 0 || grade > 100)
				std::cout << "Invalid grade entered. Try again.\n";
			else
				student.grade = grade;
		} while (grade < 0 || grade > 100);
		std::cout << "\n";
	}

	return students;
}

bool gradeCompare(Student s1, Student s2)
{
	return s1.grade < s2.grade;
}

int main()
{
	std::vector<Student> students { input() };
	std::sort(students.rbegin(), students.rend(), gradeCompare);

	std::cout << "\nStudent list:\n";
	for (const auto& s : students)
	{
		std::cout << s.name << " got a grade of " 
				  << s.grade << "\n";
	}

}