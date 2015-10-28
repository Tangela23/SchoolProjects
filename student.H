/*
  student.H

  Description:
    School project. C++
    Student class definition. Describes the student grades throughout the
    course period and calculates the student's final grades as follows:
    
    Final Theory grade:
      70% projects
      30% homework

    Final Practice grade:
      20% projects
      30% homework
      50% laboratory

    Each unexcused absence will decremen a point out of both final grades.
*/

#include <iostream.h>
#include "string.h"

#defnie STUDENT_NAMELEN 40

class Student
{
  public:
    /*
      Student
      Constructor
    */
	  Student();

    /*
      Set
      Initializes the student info.
    */
	  void  Set(const char *_name, 
              const float _homework, 
              const float _project, 
              const float _laboratory, 
              const int _absences);

    /*
      GetName
      Gets the student name.
    */
	  char *GetName();

    /*
      GetTheory
      Calculates the final theory grade.
    */
	  float GetTheory();

    /*
      GetPractice
      Calculates the final practice grade.
    */
	  float GetPractice();

  private:
    /* Student name */
	  char Name[STUDENT_NAMELEN];
    /* Homework points. */
	  float Homework;
    /* Project points. */
    float Project;
    /* Laboratory points. */
    float Laboratory;
    /* Number of unexcused absences. */
	  int Absences;
};

Student::Student()
{
	strcpy(Name, "");
	Homework   = 0.0;
  Project    = 0.0;
  Laboratory = 0.0;
	Absences   = 0;
}

void Student::Set(const char *_name, 
                  const float _homework, 
                  const float _project, 
                  const float _laboratory, 
                  const int _absences)
{
	strcpy(Name, _name);
	Homework   = _homework;
	Project    = _project;
	Laboratory = _laboratory;
	Absences   = _absences;
}

char *Student::GetName()
{
	return Name;
}

float Student::GetTheory()
{
  float total = 0.0;

  /* 70% project points */
	total += (float)((Project * 7) / 10);
  /* 30% homework points */
	total += (float)((Homework * 3) / 10);
  /* -1 point per unexcused absence */
	total -= (float)(Absences * 0.1);

	return total;
}

float Student::GetPractice()
{
  float total = 0.0;

  /* 20% homework points */
	total += (float)((Homework * 2) / 10);
  /* 30% project points */
	total += (float)((Project * 3) / 10);
  /* 50% laboratory points */
	total += (float)((Laboratory * 5) / 10);
  /* -1 point per unexcused absence */
	total -= (float)(Absences * 0.1);

	return total;
}
