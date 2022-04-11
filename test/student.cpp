//student class file
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

//Assigning placeholder values to all variables
student::student
(
	string studentId,
	string firstName,
	string lastName,
	string email,
	int age,
	int daysLeft[],
	degreeProgramEnum degreeProgram
)
	{
		setStudentId(studentId);
		setFirstName(firstName);
		setLastName(lastName);
		setEmail(email);
		setAge(age);
		setDaysLeft(daysLeft);
		setDegreeProgram(degreeProgram);
	}

//All mutators and acsessors
string student::getStudentId()
{
	return studentId;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

string student::getEmail()
{
	return email;
}

int student::getAge()
{
	return age;
}

int* student::getDaysLeft()
{
	return daysLeft;
}

degreeProgramEnum student::getDegreeProgram()
{
	return degreeProgram;
}

void student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void student::setEmail(string email)
{
	this->email = email;
}

void student::setAge(int age)
{
	this->age = age;
}

void student::setDaysLeft(int daysLeft[])
{
	this->daysLeft = new int[Days_Left];
	for (int i = 0; i < Days_Left; i++)
	{
		this->daysLeft[i] = daysLeft[i];
	}
	return;
}

void student::setDegreeProgram(degreeProgramEnum degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void student::printStudentId()
{
	cout << studentId << endl;
	return;
}

void student::printFirstName()
{
	cout << firstName << endl;
	return;
}

void student::printLastName()
{
	cout << lastName << endl;
	return;
}

void student::printEmail()
{
	cout << email << endl;
	return;
}

void student::printAge()
{
	cout << age << endl;
	return;
}

void student::printDaysLeft()
{
	int* days = getDaysLeft();
	for (int i = 0; i < Days_Left; ++i) {
		std::cout << days[i] << " ";
	}
	return;
}

//Printing only by degree program
void student::printDegreeProgram()
{
	string degreeType;
	if (degreeProgram == degreeProgramEnum::SECURITY)
	{
		degreeType = "SECURITY";
	}
	else if (degreeProgram == degreeProgramEnum::NETWORK)
	{
		degreeType = "NETWORK";
	}
	else if (degreeProgram == degreeProgramEnum::SOFTWARE)
	{
		degreeType = "SOFTWARE";
	}
	cout << degreeType << endl;

	return;
}

//method for displaying all info in classRosterArray
void student::printAllInfo()
{
	string degreeType;
	if (degreeProgram == degreeProgramEnum::SECURITY)
	{
		degreeType = "SECURITY";
	}
	else if (degreeProgram == degreeProgramEnum::NETWORK)
	{
		degreeType = "NETWORK";
	}
	else if (degreeProgram == degreeProgramEnum::SOFTWARE)
	{
		degreeType = "SOFTWARE";
	}

	cout << studentId << "   First Name: " << firstName << "   Last Name: " << lastName << "   Age: " << age << "   daysInCourse: {" << daysLeft[0] << ", " << daysLeft[1]
		<< ", " << daysLeft[2] << "}   Degree Program: " << degreeType << "." << endl;

	return;
}