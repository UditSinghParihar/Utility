#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	string name;
	fprintf(stdout, "Hello there!!\nEnter your name.\n");
	getline(cin, name);
	fprintf(stdout, "Welcome %s\n", name.c_str());
	return 0;
}