#include <iostream>

using namespace std;

class add{
	int m_i;
	static int s_mi;
public:
	add(int arg):m_i{arg}{};
	static void print_info(void){
		fprintf(stdout, "Inside static print_info\nValue of s_mi:%d\n", s_mi);

	}
	void get_mi(void){
		fprintf(stdout, "Value of m_i is:%d\n", m_i);
	}
};

	int add::s_mi = 77;

int main(int argc, char const *argv[]){
	add::print_info();
	add obj{2};
	obj.get_mi();
	obj.print_info();
	return 0;
}