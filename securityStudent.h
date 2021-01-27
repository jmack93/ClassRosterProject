#pragma once
#include "student.h"
#include <string>


class securityStudent :

	public Student

{

public:
	
	using Student::Student;
	securityStudent();

	

	Degree getDegreeProgram() override; 

	void print();

	~securityStudent();

private:

	Degree degreeType = SECURITY;
};