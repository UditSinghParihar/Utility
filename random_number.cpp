#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]){
	for(int i=0; i<10; ++i){
		const float range = 0.2;
		const int numbers = range * 200;
		const float noise = (-range) + float(rand()%(numbers))/100;
		cout << noise << endl;
	}
	return 0;
}