#include "LinkedList.h"
#include<assert.h>
#include <iostream>
using namespace std;

template<class N>
Node<N>::Node(N val) {
	value = val;
	next = 0;
}

template<class N>
LinkedList<N>::LinkedList() {
	head = 0;
	tail = 0;
	count = 0;
}

template<class N>
int LinkedList<N>::length() {
	return count;
}

template<class N>
void LinkedList<N>::append(N val) {
	Node* newNode = new Node(val);
	if (head == 0)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

template<class N>
N LinkedList<N>::at(int pos) {
	//assert(pos >= 0 && pos < count);
	Node<N>* tmp;
	tmp = head;
	for (int i = 0; i < pos; i++) //he must give me the position in zero-baised
	{
		tmp = tmp->next;
	}
	return tmp->value;
}

template<class N>
void LinkedList<N>::insertat(int pos,N val) {
	Node* newNode = new Node(val);
	Node* tmp = head;
	for (int i = 0; i < pos - 1; i++) //he must give me the position in zero-baised
	{
		tmp = tmp->next;
	}
	Node<N>* tmp2 = tmp->next;
	tmp->next = newNode;
	newNode->next = tmp2;
	count++;
}

template<class N>
void LinkedList<N>::deletat(int pos) {
	if (pos == 0)
	{
		head = head->next;
	}
	else
	{
		Node* tmp = head;
		for (int i = 0; i < pos - 1; i++) //he must give me the position in zero-baised
		{
			tmp = tmp->next;
		}
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		if (pos == count - 1)
		{
			tail = tmp;
		}
	}
	count--;
}

/*template <class N>
LinkedList<N>::~LinkedList(void)
{
	while (count != 0)
		DeleteAt(0);
}*/

template <class N>
void LinkedList<N>::display() {
	if (head != 0)
	{
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}
	else
	{
		cout << "LinkedList is empty" << endl;
	}
}