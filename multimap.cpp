#include <iostream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]){
	multimap <int, int> map;
	map.insert(pair<int, int>(3, 100));
	for (int i=0; i<10; i++)
		map.insert(make_pair<int, int>(i, i*i));
	for (multimap <int, int>::iterator itr = map.begin(); itr != map.end(); itr++)
		cout << itr->first << "\t" << itr->second<< endl;
	vector<int> v;
	for(int i=1; i<10; i++)
		v.push_back(pow(i,3));
	for(std::vector<int>::iterator itr=v.begin(); itr!=v.end(); itr++)
		cout<< *itr <<endl;
	cout << "Map size: "<< map.size() << endl <<map.empty()<< endl;
	return 0;
}