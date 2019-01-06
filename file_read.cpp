#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]){
	if(argc != 2){
		fprintf(stdout, "%s file.txt\n", argv[0]);
		return 1;
	}

	ifstream file_read{argv[1]};
	if(file_read.is_open()){
		cout << "File successfully read\n";
		string line;
		while(getline(file_read, line)){
			cout << line << endl;
		}
	}
	return 0;
}