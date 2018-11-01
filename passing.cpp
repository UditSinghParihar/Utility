#include <iostream>

using namespace std;

class test{
private:
	int m_value;
public:
	test(int value):m_value{value}{};
	void add(int num){
		m_value += num;
	}
	int get_value(void){
		return m_value;
	}
};

void array_read(int *ptr, int length){
	for (int i = 0; i < length; ++i,++ptr){
		cout << *ptr << "\t";
	}
	cout << endl;
}

int main(int argc, char const *argv[]){
	test obj{6};
	test obj1{10};
	test* ptr = &obj;
	test &reference = obj1;
	ptr->add(20);
	cout << ptr->get_value() << "\t" << obj.get_value() << endl;
	reference.add(100);
	cout <<  reference.get_value() << endl; 
	
	int arr[]{1,2,10,20,30};
	array_read(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}