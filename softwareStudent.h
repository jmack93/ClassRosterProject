#pragma once
#include "student.h"
#include <string>

class softwareStudent :
	public Student
{
public:

	using Student::Student;


	softwareStudent();


	Degree getDegreeProgram() override;

	void print();


	~softwareStudent();


private:

	Degree yourDegree = SOFTWARE;





};