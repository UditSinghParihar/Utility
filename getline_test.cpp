#include <iostream>
#include <string>
int main(int argc, char const *argv[]){
	std::cout << "Enter string !! \n";
	std::string input{};
	getline(std::cin, input);
	//fprintf(stdout, "You entered: %s\n", input);
	std::cout << "you entered: " << input;
	return 0;
}