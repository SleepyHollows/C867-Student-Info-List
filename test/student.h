//student class header file
#ifndef student_h
#define student_h
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

//Inizilizing all methods and variables for student.
class student {
public:
	student
	(
		string studentId,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysLeft[],
		degreeProgramEnum degreeprogram
	);

	const int Days_Left = 3;

	void setStudentId(string newId);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmail(string newEmail);
	void setAge(int newAge);
	void setDaysLeft(int daysLeft[]);
	void setDegreeProgram(degreeProgramEnum Degree);

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysLeft();
	degreeProgramEnum getDegreeProgram();

	void printStudentId();
	void printFirstName();
	void printLastName();
	void printEmail();
	void printAge();
	void printDaysLeft();
	void printDegreeProgram();
	void printAllInfo();

private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysLeft;
	degreeProgramEnum degreeProgram;
};
#endif


