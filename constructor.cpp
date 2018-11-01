#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Employee{
private:
	int id;
	string name;
public:
	Employee(int i = 0, string n="Mr. X"):
	id{i}, name{n}{
	cout << "Inside 2 parameterized constructor\n";
	};
	int get_id(){
		return id;
	}
	string get_name(){
		return name.c_str();
	}

};

int main(int argc, char const *argv[]){
	Employee emp1(3);
	fprintf(stdout, "Id: %d Name: %s\n", emp1.get_id(), emp1.get_name().c_str() );
	return 0;
}