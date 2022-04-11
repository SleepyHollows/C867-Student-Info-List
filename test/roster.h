//roster class header file
#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include <stdio.h>
#include <string>

using namespace std;

//roster header class iniziallizing the methods and variables for roster
class roster
{
public:
	static const unsigned int classSize = 5;
	int addIndex = -1;
	int index = 0;

	string getStudentId(int index);
	void add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgramEnum degreeprogram);
	void remove(string studentId);
	void printAll();
	void printInvalidEmails();
	void printByDegreeType(degreeProgramEnum degreeProgram);
	void printAverageDaysInCourse(string studentID);
	void parseData(string data);
	~roster();

private:
	student* classRosterArray[5];

};
#endif