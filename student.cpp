#include <iomanip>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) { this->avgDaysArray[i] = 0; }

}

Student::Student(string studentID, 
				 string firstName, 
				 string lastName, 
				 string emailAddress, 
				 int age, 
				 int avgDays[], 
				 DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) {
		this->avgDaysArray[i] = avgDays[i];
	}
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getAge() {
	return this->age;
}
int* Student::getDaysInCourse() {
	return this->avgDaysArray;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID; 
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string email) {
	this->emailAddress = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDays(int days[]) {
	for (int i = 0; i < DAYS_ARRAY_SIZE; i++)
		this->avgDaysArray[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << left << setw(5) << studentID
		 << left << setw(13) << firstName
		 << left << setw(12) << lastName
		 << left << setw(25) << emailAddress
		 << left << setw(6) << age
		 << left << setw(6) << avgDaysArray[0]
		 << left << setw(6) << avgDaysArray[1]
		 << left << setw(6) << avgDaysArray[2]
		 << left << setw(10) << degreeProgramStrings[degreeProgram] << '\n';
}

bool Student::hasInvalidEmail() {
	if (Student::getEmailAddress().find('@') == string::npos
		|| Student::getEmailAddress().find('.') == string::npos
		|| Student::getEmailAddress().find(' ') != string::npos)
		return true;
	else return false;
}

double Student::averageDaysInCourse() {
	return (getDaysInCourse()[0] + getDaysInCourse()[1] + getDaysInCourse()[2]) / 3.0;
}

void Student::printTable() {
	cout << left << setw(2) << "ID | "
		 << left << setw(12) << "First Name | "
		 << left << setw(12) << "Last Name | "
		 << left << setw(10) << "Email\t\t     | "
		 << left << setw(4) << "Age | "
		 << left << setw(17) << "Days In Courses | "
		 << left << setw(10) << "Degree Program\n";
}