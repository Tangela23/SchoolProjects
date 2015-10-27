/*
  node.H

  Description:
    School project. C++
    Node class definition. Node for a singly-linked list.
*/

#include <iostream.h>
#include <string.h>

class Node
{
	public:
		Node *next;
		int value;
		Node(Node *_next, int _value) : next(_next), value(_value) {};
		Node();
};

Node::Node()
{
  next = (Node *)0;
  value = 0;
}
