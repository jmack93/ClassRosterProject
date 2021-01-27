#pragma once
#include "degree.h"
#include <string>
#include <iostream>

// This will make it so that I don't have to specify the standard library every single time.
using namespace std;

// This will create the student class
class Student
{
public:

	const static int daysToCompleteArraySize = 3; // For use with the days to complete array

protected:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysComplete[daysToCompleteArraySize]; //Allows for an array with the size of three as defined above
	Degree degreeType;
	
public:
	
	//Constructor
	Student(string studentId, string firstName, string lastName, string email, int age, int daysComplete[], Degree degreeType);
	Student();

	//Destructor
	~Student();

	//Setters
	void setId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int daysComplete[]); 
	void setDegreeProgram(Degree degreeType);

	//Getters
	string getId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int  getAge();
	int* getDays(); 
	virtual Degree getDegreeProgram() = 0;

	virtual void print() = 0;
};
