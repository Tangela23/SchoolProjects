/*
  arrays.cpp

  Description:
    Programming exercise. C++
    Simple program that demonstrates the use of char and integer arrays.
*/

#include <stdio.h>

int main()
{
#define ARRAYS_COURSE_MAX 5

  /* Student info */
  char name[20];
  int  age;
	char courses[ARRAYS_COURSE_MAX][20];
	int  grades[ARRAYS_COURSE_MAX];
  
  int  i;

  /* Get the student info from console. */
	printf("Enter the student name:");
	scanf("%[^\n]s", &name);

	printf("Enter the student age:");
	scanf("%d", &age);

	for (i = 0; i < ARRAYS_COURSE_MAX; i++)
	{
		printf("Enter the course name %d of %d: ", (i + 1), ARRAYS_COURSE_MAX);
		scanf("%s", &courses[i]);
		printf("Enter the grade obtained in course '%s': ", courses[i]);
		scanf("%d", &grades[i]);
	}

  /* Print all student info to the standard output. */
	printf("\nName: %s", name);
	printf("\nAge: %d", age);
	for (i = 0; i < ARRAYS_COURSE_MAX; i++)
	{
		printf("\nCourse name: %s", courses[i]);
		printf("\tGrade: %d", grades[i]);
	}

	return 0;
}
