#include <iostream>
#include <string>
#include "securityStudent.h"

using namespace std;

securityStudent::securityStudent() :Student()
{
	degreeType = SECURITY;
}



Degree securityStudent::getDegreeProgram() 
{
	return SECURITY;
}

void securityStudent::print()
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

securityStudent::~securityStudent()
{
	Student::~Student();
}