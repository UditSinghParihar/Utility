#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	string name;
	cout << "Hello there!!\nEnter your name.\n";
	getline(cin, name);
	cout << "Welcome " << name << endl;
	return 0;
}