#include <iostream>
#include <fstream>

#define row 5
#define col 4

using namespace std;

int main(int argc, char const *argv[]){
	ifstream file1 {"ground_truth.txt"};
	ifstream file2 {"result.txt"};
	int gt[row][col]{};
	int result[row][col]{};
	for(int i=0; i < row; i++)
		for(int j=0; j < col; j++){
			file1 >> gt[i][j];
			file2 >> result[i][j];
 	}
 	for(int i=0; i< row; i++){
 		for(int j=0; j < col; j++){
 			cout << result[i][j] << " ";
 		}
 		cout << endl;
 	}
	return 0;
}