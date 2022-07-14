#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"



Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->ageStudent = "";
	this->daysToComplete[0] = "";
	this->daysToComplete[1] = "";
	this->daysToComplete[2] = "";
	//this->studentDegree = "";
}

Student::Student(string id, string fname, string lname, string email, string age, string days1, string days2, string days3, DegreeProgram degree) {
	this->studentID = id;
	this->firstName = fname;
	this->lastName = lname;
	this->emailAddress = email;
	this->ageStudent = age;
	this->daysToComplete[0] = days1;
	this->daysToComplete[1] = days2;
	this->daysToComplete[2] = days3;
	this->studentDegree = degree;
}

void Student::SetStudentID(string id) {
	this->studentID = id;
}

string Student::GetStudentId() const {
	return studentID;
}

void Student::SetFirstName(string fname) {
	this->firstName = fname;
}
string Student::GetFirstName() const {
	return firstName;
}

void Student::SetLastName(string lname) {
	this->lastName = lname;
}
string Student::GetLastName() const {
	return lastName;
}

void Student::SetEmailAddress(string email) {
	this->emailAddress = email;

}
string Student::GetEmailAddress() const {
	return emailAddress;
}

void Student::SetAgeStudent(string age) {
	this->ageStudent = age;
}
string Student::GetAgeStudent() const {
	return ageStudent;
}

void Student::SetDaysToComplete1(string days1) {
	this->daysToComplete[0] = days1;
}
string Student::GetDaysToComplete1() const {
	return daysToComplete[0];
}

void Student::SetDaysToComplete2(string days2) {
	this->daysToComplete[1] = days2;
}
string Student::GetDaysToComplete2() const {
	return daysToComplete[1];
}

void Student::SetDaysToComplete3(string days3) {
	this->daysToComplete[2] = days3;
}
string Student::GetDaysToComplete3() const {
	return daysToComplete[2];
}


void Student::SetDegreeProgram(DegreeProgram degree) {
	this->studentDegree = degree;
}
DegreeProgram Student::GetDegreeProgram() const {
	return studentDegree;
}

void Student::print() {
	string degreeString;
	if (studentDegree == SECURITY) degreeString = "SECURITY";
	if (studentDegree == NETWORK) degreeString = "NETWORK ";
	if (studentDegree == SOFTWARE) degreeString = "SOFTWARE";

	cout << studentID << " \t First Name: " << firstName << " \t Last Name: " << lastName << " \t Age: " << ageStudent
		<< " \tdaysInCourse: {" << daysToComplete[0] << "," << daysToComplete[1] << "," << daysToComplete[2] << "} Degree Program: " << degreeString << endl;
}