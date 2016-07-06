//reference: http://stackoverflow.com/questions/2428765/why-the-size-of-a-pointer-is-4bytes-in-c/2428809#2428809
#include <iostream>

using std::cout; using std::endl;

int main()
{
	int x[10];
	int *p = x;

	cout << sizeof(x) / sizeof(*x) << endl;//10
	cout << sizeof(p) / sizeof(*p) << endl;//2

	return 0;
}
