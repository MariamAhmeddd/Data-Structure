#include "square.h"
square::square(int h)
{
	hieght = h;
}
int square::area()
{
	return hieght * 4;
}
square::~square(void){}