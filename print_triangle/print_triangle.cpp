/*
  print_triangle.cpp

  Description:
    Programming exercise. C++

    Prints an isosceles triangle to the standard output.
*/

#include <iostream>

using std::cout;

int main(void)
{
#define TRIANGLE_HEIGHT 7

  int row, i;

  for (row = 1; row <= TRIANGLE_HEIGHT; row++)
  {
    for (i = (TRIANGLE_HEIGHT - row); i > 0; i--)
      cout<<" ";
    for (i = 1; i < (2 * row); i++)
      cout<<"*";
    cout<<"\n";
  }

  return 0;
}
