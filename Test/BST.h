#include<assert.h>
#pragma once

template <class N>
class Node 
{
	N value;
	Node* left, right;

public:
	Node(N val);
	~Node();
};

template <class N>
class BST
{
	Node<N>* root;

public:
	BST();
	bool contains(N value);
	Node<N> findNode(N value);
	Node<N> findPar(N value);
	Node<N> findMin(Node<N>* start
	);
	void insert(N value);
	void travers(int ch);
	void inOrder(Node<N>* start);
	void preOrder(Node<N>* start);
	void postOrder(Node<N>* start);
	void remove(N value);
	~BST();
};

