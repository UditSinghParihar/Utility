#include <iostream>
#include <string>

using namespace std;

class MyString{
private:
	string m_string = "Hello";
	int m_size = 1234;
public:
	MyString(const char* arg_str): m_string{arg_str}{
		cout << "Inside const char* constructor\n";
	};

	MyString(string arg_str): m_string{arg_str}{
		cout << "Inside string constructor\n";
	}

	MyString(int size): m_size{size}{
		cout << "Inside int constructor\n";
	}

	void print_info(void){
		fprintf(stdout, "String is: %s\nIts size is: %d\n", m_string.c_str(), m_size);
	}
};

int main(int argc, char const *argv[]){
	MyString character{'x'};
	// character.print_info();
	MyString name{"Udit"};
	// name.print_info();
	MyString string_name{string("Joe")};
	return 0;
}