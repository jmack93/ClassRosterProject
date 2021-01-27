#include <string>
#include <iostream>
#include <sstream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

using namespace std;

Roster::Roster()
{

}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompletion1, int daysToCompletion2, int daysToCompletion3, Degree degreeType) {

	//In order for the networkStudent, securityStudent, and softwareStudent to accept the days to completion arguments, they will need to be called to the integer completedDays[3] that I made.
	int completedDays[3] = { daysToCompletion1, daysToCompletion2, daysToCompletion3 };
	for (int i = 0; i < 5; i++) 
{
    if (classRosterArray[i] == nullptr) 
	
	{
	if (degreeType == NETWORKING) {
					classRosterArray[i] = new networkStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeType);
						break;
						}


	else if (degreeType == SECURITY) {
					classRosterArray[i] = new securityStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeType);
						break;
						}


	else if (degreeType == SOFTWARE) {
					classRosterArray[i] = new softwareStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeType);
						break;
						}

			break;

		}
	}
}

void Roster::remove(string studentId)
{
		//Loops through the array
		for (int i = 0; i < 5; i++)
		{


			if (this->classRosterArray[i] == nullptr)
			{
				// Prints to the console that the specified ID was not found.
				cout << "Student with the specified ID not found";
				
			}
			else if (this->classRosterArray[i]->getId() == studentId)
			{
				//prints to the console that the specified ID was deleted
				cout << this->classRosterArray[i]->getId() << ' ' << "was deleted";

				//Sets the specified student to a nullptr value
				this->classRosterArray[i] = nullptr;

				cout << endl;

				break;

			
			
			}
			
		}
}



void Roster::printInvalidEmails()
{
	cout << "Invalid Emails"; 
	cout << endl;

	for (int i = 0; i < 5; i++)
	{

		//This next function will check for invalid emails by making sure that they have a ".", a "@" and no spaces. Invalid emails will be printed out.
		string testEmail;
		testEmail = ((*classRosterArray[i]).getEmail());
		if (testEmail.find(".") == string::npos)
		{
			cout << testEmail;
			cout << endl;
		}
		else if
			(testEmail.find(" ") != string::npos) 
		{
			cout << testEmail;
			cout << endl;
		}
		else if (testEmail.find("@") == string::npos)
		{
			cout << testEmail; 
			cout << endl;
		
		}
		else 
		{
			break;
		
		}
		
	}
}

void Roster::printAll()
{
	//Loops through the roster and prints the student's information.
	cout << "Current Class Roster" << endl;
	for (int i = 0; i < 5; i++)
	{
		(this->classRosterArray[i]->print());

	}
	cout << endl;
}


void Roster::printByDegreeProgram(int degreeProgram)
{
	//Loops through the program and prints out students based upon a specific degree program. In this case, the instructions have us specify "SOFTWARE"
	Degree placeholder = SOFTWARE;

	if (degreeProgram == 0)
	{
		placeholder = SECURITY;

		cout << "Security Students" << endl;
	}
	if (degreeProgram == 1)
	{
		placeholder = NETWORKING;

		cout << "Networking Students" << endl;
	}

	if (degreeProgram == 2)
	{
		placeholder = SOFTWARE;
		cout << "Software Students" << endl;
	
	}

	
	for (int i = 0; i < 5; i++)
	{
		if ((*classRosterArray[i]).getDegreeProgram() == placeholder)
		{

			//This will output the student's information, except for their degree program, which will be mentioned above, to avoid redundancy.
			cout << classRosterArray[i]->getId();
			cout << ' ';
			cout << classRosterArray[i]->getFirstName();
			cout << ' ';
			cout << classRosterArray[i]->getLastName();
			cout << ' ';
			cout << classRosterArray[i]->getEmail();
			cout << ' ';
			cout << classRosterArray[i]->getDays()[0];
			cout << ' ';
			cout << classRosterArray[i]->getDays()[1];
			cout << ' ';
			cout << classRosterArray[i]->getDays()[2];
			cout << endl;
		}
	}
}

void Roster::printDaysInCourse(string studentId)
{
	
	for (int i = 0; i < 5; i++)
	{
		if (this->classRosterArray[i]->getId() == studentId) {

			
			 int* testDays = classRosterArray[i]->getDays();
			 int daysAverage = (testDays[0]+testDays[1]+testDays[2]); // This should get all of the days and divide them by three giving an average number of days


			cout << this->classRosterArray[i]->getId() << " Has an average days in course of: " << (daysAverage/3) << endl;


		}


	}
}

Roster::~Roster()

//Since we used pointers this will prevent a memory leak
{ 
		delete this->classRosterArray[0];
		delete this->classRosterArray[1];
		delete this->classRosterArray[2];
		delete this->classRosterArray[3];
		delete this->classRosterArray[4];
}

//The main function to run everything!

int main()
{

	//Student data array
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,John,McKahan,jmckah1@wgu.edu,26,10,20,30,SOFTWARE" };

	cout << "Class Name: Scripting and Programming Applications" << endl;
	cout << "Course Number: C867" << endl;
	cout << "My student ID is : " << endl;
	cout << "John McKahan II" << endl;
	cout << endl;

	//Creating an instance of the Roster called classRoster as per the instructions.
	Roster classRoster;

	//To be used to temporarily hold a degree value

	Degree holdDegree;
	
	//Adding all the students to classRoster
	for (int i = 0; i < 5; i++) {
		string spacerSpace;
		string testArray[9];
		//This is just to assign it a value temporarily. In this case, every student has a valid degree so this won't be an issue.
		holdDegree = NETWORKING;

		string testDummy = studentData[i];
		istringstream studentString(testDummy);

		//This following will loop through the values in each individual student, as they are separated by a comma, and grab the values that we need.
		int w = 0;
		while (getline(studentString, spacerSpace, ',')) {
			testArray[w] = spacerSpace;
			w++;
		}
		if (testArray[8] == "NETWORK")

			holdDegree = NETWORKING;



		else if (testArray[8] == "SOFTWARE")



			holdDegree = SOFTWARE;



		else if (testArray[8] == "SECURITY")



			holdDegree = SECURITY; 

		else {
			cout << "Oops make sure you have a valid degree";
		}

		//This will add the students to the class roster!
		classRoster.add(testArray[0], testArray[1], testArray[2], testArray[3], stoi(testArray[4]), stoi(testArray[5]), stoi(testArray[6]), stoi(testArray[7]), holdDegree);
	}
	
	
	
	//This will print all of the students and their data 
	
	classRoster.printAll();

	cout << endl;
	

	//This will print the invalid emails

	classRoster.printInvalidEmails();

	cout << endl;
	//Displaying the average days in courses by student ID

	cout << "Average Days in Courses";

	cout << endl;

	for (int i = 0; i < 5; ++i)
	{
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getId());
	}

	cout << endl;

	cout << endl;

	//This will print the class roster by degree program, in this case, it will be the SOFTWARE program

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl;

	//This will remove A3 from the class roster

	classRoster.remove("A3");

	cout << endl;
	//This will check to make sure A3 was removed

	classRoster.remove("A3");

	cout << endl;
	//This will call the destructor, as per the instructions
	classRoster.~Roster();

	//This should keep the window from automatically closing. with a "press any key to continue" to close.
	system("pause");

	//Since main isn't void it has to return something.
	return 0;

	
	
}