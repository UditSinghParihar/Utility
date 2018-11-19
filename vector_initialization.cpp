#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	const int size = 20;
	vector<bool> is_filled(size, true);
	for(size_t index=0; index<is_filled.size(); ++index){
		cout << is_filled[index] << endl;
	}
	return 0;
}