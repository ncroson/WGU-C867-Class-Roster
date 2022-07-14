#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	
	// set to int?
	string ageStudent;
	//string daysToComplete1;
	//string daysToComplete2;
	//string daysToComplete3;
	string daysToComplete[3];
	//

	DegreeProgram studentDegree;

public:
	Student();

	Student(string id, string fname, string lname, string email, string age, string days1, string days2, string days3, DegreeProgram degree);
	
	void SetStudentID(string id);
	string GetStudentId() const;

	void SetFirstName(string fname);
	string GetFirstName() const;

	void SetLastName(string lname);
	string GetLastName() const;

	void SetEmailAddress(string email);
	string GetEmailAddress() const;

	void SetAgeStudent(string age);
	string GetAgeStudent() const;

	void SetDaysToComplete1(string days1);
	string GetDaysToComplete1() const;

	void SetDaysToComplete2(string days2);
	string GetDaysToComplete2() const;

	void SetDaysToComplete3(string days3);
	string GetDaysToComplete3() const;


	void SetDegreeProgram(DegreeProgram degree);
	DegreeProgram GetDegreeProgram() const;

	void print();



};





#endif