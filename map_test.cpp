#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]){
	map <int, int> m;
	for (int i= 1; i< 10; i++){
		m.insert(pair <int, int> (i, i*i));
	}
	map <int, int> :: iterator itr;
	for (itr = m.begin(); itr != m.end(); itr++){
		cout << itr->first << "\t" << itr->second << endl;
	}
	return 0;
}