#include "QueueArr.h"
#include<assert.h>

template <class N>
QueueArr<N>::QueueArr() {
	count = 0;
	size = 10;
	arr = new N[size];
	front = -1;
	back = -1;
}

template <class N>
int QueueArr<N>::length() {
	return count;
}

template <class N>
bool QueueArr<N>::empty() {
	return (count == 0);
}

template <class N>
bool QueueArr<N>::full() {
	return (count == size);
}

template <class N>
void QueueArr<N>::enqueuq(N value) {

	assert(!full());
	//i'm inserting in the back of the queue , but what if i have some spaces in the front , as in the queue i delete from the front,
	// shouldn't i check if there spaces in the front of the queue first to save memory??
	// we always insert the new element in arr[back] right?
	// so because of this case, we can get the idx of the back by this equation
	
	back = (back + 1) % size; 
	arr[back] = value;
	count++;
	if (front == -1)
	{
		front = 0;
	}
}

template <class N>
void QueueArr<N>::dequeue() {
	assert(!empty());
	front = (front + 1) % size;
	count--;
	if (count == 0)
	{
		front = -1;
		back = -1;
	}
}

/*template <class N>
N QueueArr<N>::front() {
	return arr[front];
}*/

template <class N>
QueueArr<N>::~QueueArr() {
	delete[]arr;
}