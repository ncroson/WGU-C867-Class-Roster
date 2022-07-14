// Student System Program
// Scripting and Programming - Applications - C867
// C++
// Student ID: 001192148
// Nathan Croson
// 5/23/2020

#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
 
using namespace std;


const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Nathan,Croson,ncroson@gmail.com,34,60,60,60,SOFTWARE"
};


int main()
{
	Roster* classRoster = new Roster();
    cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "C++" << endl;
	cout << "Student ID: 001192148" << endl;
	cout << "Nathan Croson" << endl;

	for (int i = 0; i < 5; i++) {
		classRoster->add(studentData[i]);
	}
	
	cout << "Print All..." << endl;
	classRoster->printAll();
	cout << endl;
	
	cout << "Print Invalid Emails..." << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	
	cout << "Printing Average Days in course..." << endl;
	for (int i = 0; i < 5; ++i) {
		stringstream ss;
		ss << "A" << i + 1;
		string s = ss.str();
		classRoster->printAverageDaysInCourse(s);
	}
	cout << endl;

	cout << "Print by Degree Program..." << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	
	cout << "Removing A3..." << endl;
	classRoster->remove("A3");
	cout << "Printing with A3 removed..." << endl;
	classRoster->printAll();
	cout << endl;
	cout << "Trying to remove A3 again..." << endl;
	classRoster->remove("A3");

	classRoster->~Roster();
	
}

