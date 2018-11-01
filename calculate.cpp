#include <iostream>

using namespace std;

class cal{
	int my_value;
public:
	 cal(int val=0):my_value{val}{};
	~cal(){
		cout << "Inside destructor\n";
	};
	int get_value(void)const{
		return my_value;
	}
	cal& add(int num){
		my_value += num;
		return *this;
	}
	cal& substract(int num){
		my_value -= num;
		return *this;
	}
	
};

int main(int argc, char const *argv[]){
	cal obj{5};
	obj.add(20).substract(50);
	cout << obj.get_value() << endl;
	const cal obj1{6};
	cout << obj1.get_value() << endl;
	return 0;
}