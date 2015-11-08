/*
  factorial.cpp

  Description:
    Programming exercise. C++
    Simple program that calculates the factorial of an integer.
*/

#include "iostream.h"
#include "stdlib.h"

float Factorial(const int);

void main()
{
	int n;

	cout<<"Calculate factorial of n=";
	cin>>n;

	cout<<endl<<n<<"! ="<<Factorial(n)<<endl;
}

float Factorial(const int n)
{
	if (n <= 0)
		return 1;

	return n * Factorial(n - 1);
}
