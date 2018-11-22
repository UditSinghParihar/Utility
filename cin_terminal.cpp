#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	string name;
<<<<<<< HEAD
	cout << "Hello there!!\nEnter your name.\n";
	getline(cin, name);
	cout << "Welcome " << name << endl;
=======
	fprintf(stdout, "Hello there!!\nEnter your name.\n");
	getline(cin, name);
	fprintf(stdout, "Welcome %s\n", name.c_str());
>>>>>>> 39f7bb3c55e98dbf71f860f3f966ca03aee3aa0b
	return 0;
}