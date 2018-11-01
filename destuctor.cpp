#include <iostream>

using namespace std;

class simple{
private:
	int id;
public:
	simple(int ID = 0): id{ID}{
		cout << "Inside constructor " << id << endl;
	};
	~simple(){
		cout << "Inside destuctor " << id << endl;
	};
	int get_id(void){
		return id;
	}
	
};

int main(int argc, char const *argv[]){
	simple obj1(2);
	simple *ptr = new simple(4);
	cout << ptr->get_id() << endl;
	delete ptr;
	return 0;
}