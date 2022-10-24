#include<assert.h>
#pragma once
template <class N>
class QueueArr
{
public:
	N* arr;
	int count;
	int size;
	int front;
	int back;
public:
	QueueArr();
	int length();
	bool empty();
	void enqueuq(N );
	void dequeue();
	bool full();
	//N front();
	~QueueArr();

};

