//main class file
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>

using namespace std;

int main()
{
    cout << "Programming Language Used: C++" << endl;
    cout << "Name: Caleb Hathaway" << endl;
    cout << "Student ID: 005470217 " << endl << endl;

    //Student Info
    const string studentInfo[] = 
    { 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Caleb,Hathaway,hathawaycaleb@aol.com,26,9,10,7,SOFTWARE",
    };

    //Inizilizing object roster
    roster classRoster;

    //filling out the new student class objs
    for (int i = 0; i < 5; ++i) 
    {
        classRoster.parseData(studentInfo[i]);
    };

    //Printing everything in roster
    classRoster.printAll();

    //Printing invalid emails
    classRoster.printInvalidEmails();

    //Printing average days
    for (int i = 0; i < 5; ++i) 
    {
        classRoster.printAverageDaysInCourse(classRoster.getStudentId(i));
    }
    cout << endl;

    //Printing only students with network degree
    classRoster.printByDegreeType(degreeProgramEnum::SOFTWARE);
    cout << endl;

    //Removing Student with ID A3
    classRoster.remove("A3");
    cout << endl;

    //Printing everything in roster
    classRoster.printAll();
    cout << endl;

    //Showing student not found
    classRoster.remove("A3");
    cout << endl;

    //Destructor
    classRoster.~roster();
}