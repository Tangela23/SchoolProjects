/*
  factorial.cpp

  Description:
    Programming exercise. C++
    Simple program that calculates the factorial of an integer.
*/

#include <iostream>

using std::cout;
using std::cin;

float Factorial(const int);

int main(void)
{
  int n;

  cout<<"Calculate factorial of n: ";
  cin>>n;

  cout<<"\n"<<n<<"! = "<<Factorial(n)<<"\n";

  return 0;
}

float Factorial(const int n)
{
  if (n <= 0)
    return 1;

  return n * Factorial(n - 1);
}
