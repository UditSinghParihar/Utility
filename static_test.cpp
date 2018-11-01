#include <iostream>

using namespace std;

void foo1(void){
	cout << "Inside foo1\n";
}

void foo2(void){
	static int count = 0;
	if(count%3 == 0)
		foo1();
	cout << "count value: " << count << endl;
	++count;
}

int main(int argc, char const *argv[])
{
	/* code */
	for(int i=0; i<20; i++)
		foo2();
	return 0;
}