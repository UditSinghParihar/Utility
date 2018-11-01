#include <iostream>
#include <string>

using namespace std;
class test{
public:
	void change(int &num)const{
		++num;
	}
	void excess(void){
		int num =0;
		fprintf(stdout,"Before %d\n", num);
		change(num);
		fprintf(stdout, "After %d\n", num);
	}

};

int main(int argc, char const *argv[]){
	std::string str = "Hello world: ";
	for(int i=0; i<10; i++)
		std::cout << str + std::to_string(i) << std::endl;
	std::string input1, input2;
	std::cout << "Enter 2 random texts!!!\n";
	//getline(std::cin, input);
	cin >> input1 >> input2;
	std::cout << "You entered: " << input1 << " and "<< input2 <<std::endl;
	test obj;
	obj.excess();
	return 0;
}
	