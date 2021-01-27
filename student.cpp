#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;


//Constructor

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName  = "";
	this->email     = "";
	this->age       =  0;
	for (int i = 0; i < 3; i++) this->daysComplete[i] = 0;
	
	
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysComplete[], Degree degreeType)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysComplete[i] = daysComplete[i];
}

//Setters

void Student::setAge(int age)
{
	this->age = age;


}

void Student::setId(string studentId)
{
	this->studentId = studentId;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setDays(int daysComplete[])
{
	for (int i = 0; i < daysToCompleteArraySize; i++) this->daysComplete[i] = daysComplete[i];
}

void Student::setDegreeProgram(Degree degreeType)
{
	//Left blank as per the instructions
}

//Getters

string Student::getId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return this->daysComplete;
}

	Degree Student::getDegreeProgram()
	{
		 // To be left blank as per the instructions but my code will not compile without this returning a value
		return degreeType;
	}



//Print

void Student::print()
{
	cout << getId() << ' ' << ' ';
	cout << getFirstName() << ' ' << ' ';
	cout << getLastName() << ' ' << ' ';
	cout << getAge() << ' ' << ' ';
	cout << getEmail() << ' ' << ' ';
	// cout << getDegreeProgram() << ' ' << ' ' << ' '; 
	cout << getDays()[0] << ' ';
	cout << getDays()[1] << ' ';
	cout << getDays()[2] << ' ';
	cout << endl;
		 
}

//Destructor

Student::~Student()
{

}