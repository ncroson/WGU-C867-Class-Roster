#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"



using namespace std;

/*
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Nathan,Croson,ncroson@gmail.com,34,60,60,60,SOFTWARE"
};
*/



Roster::Roster() {
	lastIndex = -1;
	numStudents = 5;
	classRosterArray[0] = new Student;
	classRosterArray[1] = new Student;
	classRosterArray[2] = new Student;
	classRosterArray[3] = new Student;
	classRosterArray[4] = new Student;
	
}

Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
	}
}

void Roster::add(string row) {

	
	if (lastIndex < 5) {
		lastIndex++;
		//double dayArray[3];

	}
	

	//ID
	int rhs = row.find(",");
	//cout << row.substr(0, rhs) << " ";
	classRosterArray[lastIndex]->SetStudentID(row.substr(0, rhs));

	//First Name
	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << row.substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetFirstName(row.substr(lhs, rhs - lhs));

	//Last Name
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetLastName(row.substr(lhs, rhs - lhs));

	//Email
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetEmailAddress(row.substr(lhs, rhs - lhs));

	//Age
	//Days 1
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetAgeStudent(row.substr(lhs, rhs - lhs));

	//Days 1
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetDaysToComplete1(row.substr(lhs, rhs - lhs));

	//Days 2
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetDaysToComplete2(row.substr(lhs, rhs - lhs));

	//Days 3
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
	classRosterArray[lastIndex]->SetDaysToComplete3(row.substr(lhs, rhs - lhs));

	//Degree Program
	lhs = rhs + 1;
	//rhs = studentData[lastIndex].find(",", lhs);
	//cout << studentData[lastIndex] << ' ';
	DegreeProgram type;
	if (row.substr(lhs) == "SECURITY") type = SECURITY;
	if (row.substr(lhs) == "NETWORK") type = NETWORK;
	if (row.substr(lhs) == "SOFTWARE") type = SOFTWARE;

	classRosterArray[lastIndex]->SetDegreeProgram(type);

	cout << endl;
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

}


void Roster::remove(string studentID) {
	bool foundID = false;
	

	for (int i = 0; i < numStudents; ++i) {

		if (classRosterArray[i]->GetStudentId() == studentID) {

			delete classRosterArray[i];
			numStudents--;
			foundID = true;
			for (int j = i; j < numStudents; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			break;
		}
	}
	
	if (foundID == false) {
		cout << "Student with ID: " << studentID << " not found." << endl;
	}

}

void Roster::printAll() {
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->print();
	
		/*
		cout << "Student " << i << endl;
		cout << "ID: " << classRosterArray[i]->GetStudentId() << endl;;
		cout << "First Name: " << classRosterArray[i]->GetFirstName() << endl;
		cout << "Last Name: " << classRosterArray[i]->GetLastName() << endl;
		cout << "Email: " << classRosterArray[i]->GetEmailAddress() << endl;
		cout << "Age: " << classRosterArray[i]->GetAgeStudent() << endl;
		cout << "Days 1: " << classRosterArray[i]->GetDaysToComplete1() << endl;
		cout << "Days 2: " << classRosterArray[i]->GetDaysToComplete2() << endl;
		cout << "Days 3: " << classRosterArray[i]->GetDaysToComplete3() << endl;
		cout << "Degree: " << classRosterArray[i]->GetDegreeProgram() << endl;
		*/
		;
		
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int daysAverage;
	int i;
	int day1, day2, day3 = 0;
	string numExtract;

	numExtract = studentID.substr(1);
	i = atoi(numExtract.c_str()) - 1;
	day1 = stoi(classRosterArray[i]->GetDaysToComplete1());
	day2 = stoi(classRosterArray[i]->GetDaysToComplete2());
	day3 = stoi(classRosterArray[i]->GetDaysToComplete3());
	
	daysAverage = (day1 + day2 + day3) / 3;

	cout << studentID << " Average days in course: " << daysAverage << endl;

}

void Roster::printInvalidEmails() {
	
	for (int i = 0; i < 5; ++i) {
		int foundSpace = -1;
		int missingDot = -1;
		int missingAt = -1;
		foundSpace = classRosterArray[i]->GetEmailAddress().find(" ", 0);
		missingDot = classRosterArray[i]->GetEmailAddress().find(".", classRosterArray[i]->GetEmailAddress().length() - 5);
		missingAt = classRosterArray[i]->GetEmailAddress().find("@", 0);

		if (foundSpace != -1 || missingDot == -1 || missingAt == -1) {
			cout << " Invalid email address: " << classRosterArray[i]->GetEmailAddress() << endl;
		}

	}

}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (int i = 0; i < numStudents; ++i) {
		if (degreeprogram == classRosterArray[i]->GetDegreeProgram()) {
			classRosterArray[i]->print();
		}
	}

}