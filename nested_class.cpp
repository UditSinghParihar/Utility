#include <iostream>
#include <string>

using namespace std;

class house{
	int m_house_number;
	string m_house_owner;
public:
	house(int house_number=2, string house_owner="jerry"):
	m_house_number{house_number}, m_house_owner{house_owner}{};
	void get_info(void){
		fprintf(stdout, "house_number: %d\nhouse_owner: %s\n", m_house_number, m_house_owner.c_str());
	}
};

class test{
public:
	test(){};
	void get_info(){
		cout << "Inside test::get_info\n";
	}
};

int main(int argc, char const *argv[]){
	house(23, "john").get_info();
	house().get_info();
	test().get_info();
	return 0;
}