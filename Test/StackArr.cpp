#include "StackArr.h"
#include <assert.h>
StackArr::StackArr() {
	count = 0;
	size = 10;
	arr = new int[size];
}

int StackArr::lenght() {
	return count;
}

bool StackArr::empty() {
	return(count == 0);
}

void StackArr::expand() {
	size += 5;
	int* temparr = new int[size];
	for (int i = 0; i < count; i++)
	{
		temparr[i] = arr[i];
	}
	delete[]arr;
	arr = temparr;
}

void StackArr::push(int value) {
	if (count == size) {
		expand();
	}
	else {
		arr[count] = value;
		count++;
	}
}

void StackArr::pop() {
	assert(!empty());
	count--;
}

int StackArr::top() {
	assert(!empty());
	return arr[count - 1];
}

StackArr::~StackArr(void){
	delete[]arr;
}