/*
  print_triangle.cpp
  Programming exercises. C++
  Print an isosceles triangle to the standard output.
*/

#include "iostream.h"

void main ()
{
	int rows = 5, row, i, j;

	for (row = 1; row <= rows; row++)
	{
		for (i = (rows - row); i > 0; i--)
			cout<<" ";
		for (j = 1; j < (2 * row); j++)
			cout<<"*";
		cout<<endl;
	}
}
