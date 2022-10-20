#include<iostream>
#include<stdlib.h>
using namespace std;
unsigned int test()
{
	return rand();
}

int main()
{
	srand((unsigned int) time(NULL));
	for(int i = 0; i < 10; ++i)
	{
		cout << "rand: " << test() << endl;
	}

	return 0;
}
