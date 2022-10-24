#include "BST.h"
#include<iostream>
using namespace std;
template <class N>
Node<N>::Node(N val)
{
	value = val;
	left = 0;
	right = 0;

}

template <class N>
BST<N>::BST()
{
	root = 0;
}

template<class N>
void BST<N>::remove(N value)
{
	if (root == 0)
	{
		return;
	}


	Node<N>* node = findNode(value);
	Node<N>* parent = findPar(value);
	
	if (node->left == 0 && node->right == 0) // leaf node
	{
		if (root == node)
		{
			root = 0;
		}
		else
		{
			if (value < parent->value)
			{
				parent->left = 0;
			}
			else
			{
				parent->right = 0;
			}
		}
		delete node;
	}
	else if (node->left == 0 && node->right != 0) // have one child in the right
	{
		if (root == node)
		{
			root = node->right;
		}
		else
		{
			if (value < parent->value)
			{
				parent->left = node->right;
			}
			else
			{
				parent->right = node->right;
			}
		}
		delete node;
	}
	else if (node->left != 0 && node->right == 0) // have one child in the left
	{
		if (root == node)
		{
			root = node->left;
		}
		else
		{
			if (value < parent->value)
			{
				parent->left = node->left;
			}
			else
			{
				parent->right = node->left;
			}
		}
		delete node;
	}
	else
	{
		Node<N>* minNode = findMin(node);
		Node<N>* parOFMin = findPar(minNode->value);
		node->value = minNode->value;
		if (node == parOFMin)
		{
			parent->right = minNode->right;
		}
		else
		{
			parent->left = minNode->right;
		}
		delete minNode;
	}
}

template <class N>
Node<N> BST<N>::findNode(N value)
{
	Node<N>* tmp = root;
	while (tmp!=0)
	{
		if (value > tmp->vaule)
		{
			tmp = tmp->right;
		}
		else if (value < tmp->vaule)
		{
			tmp = tmp->left;
		}
		else
		{
			break;
		}
	}
	return tmp;
}

template <class N>
Node<N> BST<N>::findMin(Node<N>* start)
{
	Node<N>* minNode = start->right;
	while (minNode != 0)
	{
		minNode = minNode->left;
	}
	return minNode;
}

template <class N>
Node<N> BST<N>::findPar(N value)
{
	Node<N>* tmp = root;
	Node<N>* par = root;
	while (tmp != 0 && value != tmp->vaule)
	{
		par = tmp;
		if (value > tmp->vaule)
		{
			tmp = tmp->right;
		}
		else if (value < tmp->vaule)
		{
			tmp = tmp->left;
		}
	}
	return par;
}


template <class N>
bool BST<N> ::contains(N value)
{
	Node<N>* tmp = findNode(value);
	if (tmp != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class N>
void BST<N>::insert(N value)
{
	assert(!contains(value)); //to check if the value is already exist
	Node<N>* node = new Node(value);
	if (root == 0)
	{
		root = node;
	}
	else
	{
		Node<N>* tmp = root;
		while (true)
		{
			if (value > tmp->vaule)
			{
				if (tmp->right == 0)
				{
					tmp->right = node;
					break;
				}
				else
				{
					tmp = tmp->right;
				}
			}
			else
			{
				if (tmp->left == 0)
				{
					tmp->left = node;
					break;
				}
				else
				{
					tmp = tmp->left;
				}
			}
		}
	}
}

template <class N>
void BST<N>::travers(int ch)
{
	if (ch == 1)
	{
		inOrder(root);
	}
	else if (ch == 2)
	{
		preOrder(root);
	}
	else
	{
		postOrder(root);
	}
}

template <class N>
void BST<N>::inOrder(Node<N>* start)
{
	if (start != 0)
	{
		inOrder(start->left);
		cout << start->vaule << endl;
		inOrder(start->right);
	}
}

template <class N>
void BST<N>::preOrder(Node<N>* start)
{
	if (start != 0)
	{
		cout << start->vaule << '\n';
		preOrder(start->left);
		preOrder(start->right);
	}
}

template <class N>
void BST<N>::postOrder(Node<N>* start)
{
	if (start != 0)
	{
		postOrder(start->left);
		postOrder(start->right);
		cout << start->vaule << endl;
	}
}
