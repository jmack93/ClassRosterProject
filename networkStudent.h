#pragma once
#include "student.h"
#include <string>


class networkStudent :

	public Student
{
public:

	using Student::Student;

	networkStudent();

	Degree getDegreeProgram() override;
	
	void print();


	~networkStudent();
	
private:
	Degree degreeType = NETWORKING;


};
