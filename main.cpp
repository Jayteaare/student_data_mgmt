#include <iostream>
#include "roster.h"

using namespace std;

int main() {
	cout << "Class: Scripting and Programming - Applications (C867)\n"
		 << "Language: C++\n"
		 << "Student ID: 010568563\n"
		 << "Student Name: Tallis Jordan\n\n";

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Tallis,Jordan,tjor195@wgu.edu,26,16,22,18,SOFTWARE"
	};

	const int NUM_STUDENTS = 5;

	Roster roster;

	for (int i = 0; i < NUM_STUDENTS; i++)
		roster.parse(studentData[i]);

	roster.printAll();
	cout << '\n';

	roster.printInvalidEmails();
	cout << '\n';

	cout << "Average days spent in a course per student: \n";
	for (int i = 0; i < NUM_STUDENTS; i++) {
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
	}
	cout << '\n';

	roster.printByDegreeProgram(SOFTWARE);

	roster.remove("A3");

	roster.printAll();
	cout << '\n';

	roster.remove("A3");

	return 0;
}