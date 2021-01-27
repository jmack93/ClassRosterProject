#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include <array>

class Roster {

public:

	Roster();

	void add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(string studentId);
	void printDaysInCourse(string studentId);
	void printInvalidEmails();
	void printAll();
	void printByDegreeProgram(int degreeProgram);

	~Roster();


	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

};