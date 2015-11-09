/*
  node.H

  Description:
    School project. C++
    Node class definition. Node for a singly-linked list.
*/

class Node
{
  public:
    /*
      Node
      In-line constructor
    */
    Node(Node *_next, int _value) : next(_next), value(_value) {};
    /*
      Node
      Constructor
    */
    Node();

    Node *next;
    int   value;
};

Node::Node()
{
  next  = (Node *)0;
  value = 0;
}
