/*
  list.H

  Description:
    School project. C++
    List class definition. Singly-linked list with a bubble sort routine.
*/

#include <iostream.h>
#include <string.h>
#include "node.h"

class List
{
	public:
		List();
		void Push(int);
		int Pop();
		void BubbleSort();
		void Print();
	private:
		Node *head;
		Node *tail;
		int node_count;
};

List::List()
{
	node_count = 0;
	head = NULL;
}

void List::Push(int _value){
	Node * new_node;
	new_node = new Node;
	new_node->value = _value;
	new_node->next = head;

	head = new_node;
	node_count ++;
}

int List::Pop()
{
	Node * tmp_node;

	tmp_node = new Node;
	if(head != NULL)
	{
		tmp_node = head;
		head = head->next;
	}
	return tmp_node->value;
}

void List::BubbleSort()
{
	Node * node_a;
	Node * node_b;
	Node * tmp_node;

	tmp_node = new Node;
	for(node_a = head; node_a != NULL; node_a = node_a->next)
		for(node_b = node_a->next; node_b != NULL; node_b = node_b->next)
			if(node_a->value > node_b->value)
			{
				tmp_node->value = node_b->value;
				node_b->value = node_a->value;
				node_a->value = tmp_node->value;
			}
}

void List::Print()
{
	Node * curr;

	for(curr = head; curr != NULL; curr = curr->next){
		cout<<curr->value<<endl;
	}
}
