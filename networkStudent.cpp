#include <iostream>
#include "networkStudent.h"
using namespace std;


//Constructor

networkStudent::networkStudent() :Student()
{
    degreeType = NETWORKING;
}


Degree networkStudent::getDegreeProgram()
{
    return NETWORKING;
}

void networkStudent::print()
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


 networkStudent::~networkStudent()
{
    Student::~Student();
}