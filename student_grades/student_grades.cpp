/*
  student_grades.cpp

  Description:
    School project. C++
    Demonstrates the use of the Student class. The user may input a set of
    student names and their grading points, and this program will calculate
    and print the final overall grades of those students.
*/

#include <iostream>
#include "student.H"

using std::cout;
using std::endl;
using std::cin;

#define GRADES_MAXSTUDENTS ((int)20)

#define GRADES_OPTION_ADD  ((int)1)
#define GRADES_OPTION_CALC ((int)2)
#define GRADES_OPTION_EXIT ((int)3)

int main(void)
{
  Student students[GRADES_MAXSTUDENTS];
  int     student_cnt = 0;

  char  name[STUDENT_NAMELEN];
  float homework;
  float project;
  float laboratory;
  int   absences;

  int op;

  int i;

  do
  {
    /* Print the main menu. */
    cout<<endl;
    cout<<"1) Add student info\n2) Calculate final grades"<<endl<<"3) Exit"<<endl;
    cout<<"Select an option: ";
    cin>>op;
    cout<<endl;
    
    switch (op)
    {
      case GRADES_OPTION_ADD:
        if (student_cnt >= GRADES_MAXSTUDENTS)
        {
          cout<<endl<<"Maximum number of students reached"<<endl;
          break;
        }

        /* Capture the student info. */
        cout<<endl<<"Enter the student name: ";
        cin>>name;
        cout<<"Homework points: ";
        cin>>homework;
        cout<<"Project points: ";
        cin>>project;
        cout<<"Laboratory points: ";
        cin>>laboratory;
        cout<<"Number of unexcused absences: ";
        cin>>absences;

        /* Add the student to the data set. */
        students[student_cnt].Set(name, homework, project, laboratory, absences);
        student_cnt++;
        break;

      case GRADES_OPTION_CALC:
        /* Calculate and print the overall final grade for each student. */
        cout<<endl<<"Name\tPractice\tTheory\n"<<endl;
        for (i = 0; i < student_cnt; i++)
        {
          cout<<students[i].GetName()<<"\t"<<students[i].GetPractice()<<"\t\t"<<students[i].GetTheory()<<endl;
        }
        break;
    }
  } while (op != GRADES_OPTION_EXIT);

  return 0;
}
