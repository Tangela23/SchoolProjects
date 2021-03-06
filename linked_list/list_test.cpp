/*
  list_test.cpp

  Description:
    School project. C++
    Program to test the singly-linked list class.
*/

#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

int main(void)
{
  List mylist;

  mylist.Pop();
  mylist.Push(5);
  mylist.Push(3);
  mylist.Push(8);
  mylist.Push(2);
  mylist.Push(7);
  mylist.Push(1);
  mylist.Pop();

  mylist.Print();

  mylist.BubbleSort();

  cout<<"Sorted list: "<<endl;
  mylist.Print();

  return 0;
}
