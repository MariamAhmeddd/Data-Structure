#include <iostream>
#include "square.h"
using namespace std;
/*template <class T>
struct N {
	T value;

};*/
int main()
{
	square s(4);
	cout << s.area();
}