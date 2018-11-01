// function templates
#include <iostream>
#include "myclass.h"
using namespace std;

template <class T, class U>
bool are_equal (T a, U b)
{
  return (a==b);
}

int point(){
	int num[5];
	int *p;
	p = num;
	*p = 10;
	p = &num[1]; *p = 20;
	p = num; *(p+2) = 30;
	p += 3; *p = 40;
	*(++p) = 50;
	for(int i = 0; i < 5; i++)
		cout << num[i] <<endl;
	return 0;
}

class rectangle
{
private:
	int width,breadth;
public:
	rectangle(int, int);
	int get_area(void);
	
};

rectangle::rectangle(int a, int b){
	width = a;
	breadth = b;
}

int rectangle::get_area(void){
	return width * breadth;
}



int main ()
{	
  point();
  test_class obj;
  obj.value = 5;
  cout << obj.value << endl;
  obj.foo();
  rectangle obj_a(2,3);
  cout << obj_a.get_area() << endl;
  return 0;	
  if (are_equal(10,10.0))
    cout << "x and y are equal\n";
  else
    cout << "x and y are not equal\n";
  
  cout << __TIME__ << endl ;
  int a = 34;
  int *b = &a;
  cout << b << *b << endl;

return 0;
}
