#include <string>
#include <iomanip>
#include "roster.h"

using namespace std;

void Roster::parse(string studentData) {
	auto index = studentData.find(",");
	auto studentID = studentData.substr(0, index);
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto firstName = studentData.substr(0, index);
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto lastName = studentData.substr(0, index);
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto emailAddress = studentData.substr(0, index);
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto age = stoi(studentData.substr(0, index));
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto daysInCourse1 = stoi(studentData.substr(0, index));
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto daysInCourse2 = stoi(studentData.substr(0, index));
	studentData = studentData.substr(index + 1);

	index = studentData.find(",");
	auto daysInCourse3 = stoi(studentData.substr(0, index));
	studentData = studentData.substr(index + 1);

	auto degreeProgramString = studentData;


	DegreeProgram degreeProgram;
	if (degreeProgramString == "SECURITY") { 
		degreeProgram = SECURITY;
	}
	if (degreeProgramString == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}
	if (degreeProgramString == "NETWORK") {
		degreeProgram = NETWORK;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID,
				 string firstName,
				 string lastName,
				 string email,
				 int age,
				 int daysInCourse1,
				 int daysInCourse2,
				 int daysInCourse3,
				 DegreeProgram degreeProgram) {

	int daysInCourseArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++index] = new Student(studentID, firstName, lastName, email, age, daysInCourseArray, degreeProgram);
}

void Roster::remove(string studentID) {
	cout << "Removing student with ID " << studentID << " from the class roster.\n\n";
	bool found = false;
	for (int i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			if (i < NUM_STUDENTS - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[NUM_STUDENTS - 1];
				classRosterArray[NUM_STUDENTS - 1] = temp;
			}
			Roster::index--;
			auto temp = classRosterArray[2];
			classRosterArray[2] = classRosterArray[3];
			classRosterArray[3] = temp;
		}
	}
	if (found)
		cout << "Student with ID " << studentID << " has been removed from the class roster:\n\n";
	else cout << "Student with ID " << studentID << " was not found in the class roster.\n\n";

}

void Roster::printAll() {
	cout << "Class Roster:\n";
	Student::printTable();
	for (int i = 0; i <= index; i++)
		classRosterArray[i]->print();
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << "ID ";
	for (int i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << classRosterArray[i]->getStudentID() << ": "
				 << classRosterArray[i]->averageDaysInCourse() << '\n';
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "The following students have invalid email addresses:\n\n";
	bool hasInvalidEmail = false;
	for (int i = 0; i < Roster::index; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find("@") == string::npos ||
			email.find(".") == string::npos ||
			email.find(" ") != string::npos)
			cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName()
			<< " has an invalid email address of: " << email << "\n";
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in " << degreeProgramStrings[2] << " degree program:\n";
	Student::printTable();
	for (int i = 0; i <= Roster::index; i++)
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
			classRosterArray[i]->print();
	cout << '\n';
}

Roster::~Roster() {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}