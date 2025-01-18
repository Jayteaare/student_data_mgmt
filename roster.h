#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;

class Roster {
public:
	const static int NUM_STUDENTS = 5;

	void parse(string studentData);
	void add(string studentId,
			 string firstName,
			 string lastName,
			 string emailAddress,
			 int age,
			 int daysInCourse1,
			 int daysInCourse2,
			 int daysInCourse3,
			 DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();

	int index = -1;
	Student* classRosterArray[NUM_STUDENTS];
};

#endif //ROSTER_H
