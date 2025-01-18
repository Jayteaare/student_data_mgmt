#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {

public:
	const static int DAYS_ARRAY_SIZE = 3;

	Student();
	Student(string studentID, 
			string firstName, 
			string lastName, 
			string emailAddress, 
			int age, 
			int avgDays[], 
			DegreeProgram degreeProgram);
	~Student();

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();

	bool hasInvalidEmail();
	double averageDaysInCourse();
	static void printTable();
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int avgDaysArray[DAYS_ARRAY_SIZE];
	DegreeProgram degreeProgram;
};

#endif //STUDENT_H