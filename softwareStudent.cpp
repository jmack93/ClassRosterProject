#include <iostream>
#include "softwareStudent.h"
//using namespace std;

softwareStudent::softwareStudent() : Student()
{
	setDegreeProgram(SOFTWARE);
}




Degree softwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void softwareStudent::print()

//Print function, accessors are used to access the information, in the case of the 
	{
	
	cout << getId() << ' ' << ' ';
	cout << getFirstName() << ' ' << ' ';
	cout << getLastName() << ' ' << ' ';
	cout << getAge() << ' ' << ' ';
	cout << getEmail() << ' ' << ' ';
	cout << degreeTypeStrings[getDegreeProgram()] << ' ' << ' ' << ' ';
	cout << getDays()[0] << ' ';
	cout << getDays()[1] << ' ';
	cout << getDays()[2] << ' ';
	cout << endl;


	}


softwareStudent::~softwareStudent()
{
	Student::~Student();
}