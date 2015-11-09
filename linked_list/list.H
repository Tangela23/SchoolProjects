/*
  list.H

  Description:
    School project. C++
    List class definition. Singly-linked list with a bubble sort routine.
*/

#include <iostream>
#include "node.H"

using std::cout;
using std::endl;

class List
{
  public:
    /*
      List
      Constructor
    */
    List();

    /*
      Push
      Adds a node to the Head of the list.
    */
    void Push(int _value);

    /*
      Pop
      Removes a node from the head of the list, which was the last node to
      be added (last in, first out).
      Returns the integer value of the node removed; or zero for an empty list.
    */
    int  Pop();

    /*
      BubbleSort
      Sorts the list in ascending order based on the node's value, using the
      Bubble Sort algorithm.
      
      NOTE: The list is ordered in place, instead of ordering the nodes, the
      values in the nodes are updated to be in order. This is not the expected
      behaviour of a linked list but for the scope of this project is fine.
    */
    void BubbleSort();
    
    /*
      Print
      Prints the content of the list.
    */
    void Print();

  private:
    /* Head of the list. */
    Node *Head;

    /* Number of nodes in the list. */
    int   NodeCount;
};

List::List()
{
  Head = NULL;
  NodeCount = 0;
}

void List::Push(int _value)
{
  Node *new_node;

  new_node = new Node;
  new_node->next  = Head;
  new_node->value = _value;

  Head = new_node;
  NodeCount++;
}

int List::Pop()
{
  int tmp_value;
  
  if (Head == NULL)
    return 0;

  tmp_value = Head->value;
  Head = Head->next;
  NodeCount--;

  return tmp_value;
}

void List::BubbleSort()
{
  Node *node_a;
  Node *node_b;
  int   tmp_value;

  for (node_a = Head; node_a != NULL; node_a = node_a->next)
    for (node_b = node_a->next; node_b != NULL; node_b = node_b->next)
      if (node_a->value > node_b->value)
      {
        tmp_value = node_b->value;
        node_b->value = node_a->value;
        node_a->value = tmp_value;
      }
}

void List::Print()
{
  Node *curr;
  int   i = 0;

  cout<<"Linked list:"<<endl;
  for(curr = Head; curr != NULL; curr = curr->next){
    cout<<"Node["<<(i++)<<"] = "<<curr->value<<endl;
  }
}

