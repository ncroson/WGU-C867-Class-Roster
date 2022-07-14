#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "degree.h"
#include "student.h"

using namespace std;


class Roster {
private:
	Student* classRosterArray[5];
	int lastIndex;
	int numStudents;

public:
	
	Roster();
	~Roster();
	
	void add(string row);

	
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	
	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeprogram);
	
};

#endif