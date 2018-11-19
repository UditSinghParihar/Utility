#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
	vector<pair<int, bool>> list;
	list.push_back(make_pair(2, false));
	list.push_back(make_pair(2, true));
	list.push_back(make_pair(5, false));
	list.push_back(make_pair(10, true));
	std::pair<int, bool> element = std::make_pair(5, false);
	auto iter = std::find(list.begin(), list.end(), element);
	int index = distance(list.begin(), iter);
	cout << "element found at: " << index << endl;
	return 0;
}