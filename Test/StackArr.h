#include<assert.h>
#pragma once
class StackArr
{
public:
	int* arr;
	int count;
	int size;
public:
	StackArr();
	int lenght();
	void push(int );
	void pop();
	int top();
	bool empty();
	void expand();
	~StackArr();
};

