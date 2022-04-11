//roster class file
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

/*
* method for add new students to classRosterArray
* pulls data from roster::parseData
*/
void roster::add
(
	string studentId,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	degreeProgramEnum degreeprogram
)
{
	int daysLeft[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++addIndex] = new student(studentId, firstName, lastName, email, age, daysLeft, degreeprogram);
}

//it loops through and finds each , and cuts off the substring so that it can be stored in the proper variable
void roster::parseData(string record) {
	std::vector<string> tokens;
	degreeProgramEnum degree;
	for (int i = 0; i < classSize; ++i) {
		std::stringstream ss(record);

		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			tokens.push_back(subStr);
		}

		if (tokens[8] == "SECURITY") {
			degree = degreeProgramEnum::SECURITY;
		}
		if (tokens[8] == "NETWORK") {
			degree = degreeProgramEnum::NETWORK;
		}
		if (tokens[8] == "SOFTWARE") {
			degree = degreeProgramEnum::SOFTWARE;
		}
	}
	roster::add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)),
		stoi(tokens.at(6)), stoi(tokens.at(7)), degree);
}

string roster::getStudentId(int index)
{
	string id = classRosterArray[index]->getStudentId();
	return id;
}

//method to remove student from the roster
void roster::remove(string id) 
{
	bool foundStudent = false;
	for (int i = 0; i < classSize; ++i) 
	{
		if (classRosterArray[i] == nullptr) 
		{
			continue;
		}
		else if (id == classRosterArray[i]->getStudentId()) 
		{
			classRosterArray[i] = nullptr;
			foundStudent = true;
			break;
		}
	}
	if (foundStudent == false) 
	{
		cout << "Error: Student " << id << " Not Found." << endl;
	}
	else if (foundStudent == true) 
	{
		cout << "Student " << id << " removed." << endl;
	}
	return;
}
//Print all students in the roster
void roster::printAll() 
{
	cout << "All current students: " << endl;
	for (int i = 0; i < classSize; ++i) 
	{
		if (classRosterArray[i] == nullptr) { continue; }

		else { classRosterArray[i]->printAllInfo(); }
	}
	cout << endl;
	return;
}
//method for printing the average number of days
void roster::printAverageDaysInCourse(string id) 
{
	for (int k = 0; k < classSize; ++k) {
		if (id == classRosterArray[k]->student::getStudentId()) {
			int* days = classRosterArray[k]->getDaysLeft();
			std::cout << id << "'s average days in course: ";
			int avgDays = (days[0] + days[1] + days[2]) / 3;
			std::cout << avgDays << std::endl;
		}
	}
	return;
}

//method for finding and printing invalid emails
void roster::printInvalidEmails() 
{
	for (int i = 0; i < classSize; ++i) 
	{
		string badEmail = classRosterArray[i]->getEmail();
		if ((badEmail.find(' ') != string::npos) || (badEmail.find('.') == string::npos) || (badEmail.find('@') == string::npos)) 
		{
			cout << classRosterArray[i]->getStudentId() << "'s email address " << badEmail << " is invalid." << endl;
		}
	}
	cout << endl;
	return;
}

//prints students with a specified degree program
void roster::printByDegreeType(degreeProgramEnum degreeProgram) 
{
	string degreeString;
	if (degreeProgram == degreeProgramEnum::SECURITY) { degreeString = "SECURITY"; }

	else if (degreeProgram == degreeProgramEnum::NETWORK) { degreeString = "NETWORK"; }

	else if (degreeProgram == degreeProgramEnum::SOFTWARE) { degreeString = "SOFTWARE"; }

	else { degreeString = "ERROR"; }

	cout << "Students with degree program: " << degreeString << endl;
	int numStudents = 0;
	for (int i = 0; i < classSize; ++i) 
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->printAllInfo();
			++numStudents;
		}
	}

	if (numStudents == 0) { cout << "No students with this degree found." << endl; }

	return;
}

//Destructor
roster::~roster() {}