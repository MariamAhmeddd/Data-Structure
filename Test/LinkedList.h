#include<assert.h>
#pragma once

template <class N>
class Node 
{
public :
	N value;
	Node* next; //pointer to the next node
public :
	Node(N val);
	~Node();
};
template<class N>
class LinkedList
{
	int count; //num of elements in the linkedlist
	Node<N>* head;
	Node<N>* tail;

public:
	LinkedList();
	int length();
	void append(N ); //add element in the end of the linkedlist
	N at(int );
	void insertat(int , N );
	void deletat(int );
	void display();
	~LinkedList();
};