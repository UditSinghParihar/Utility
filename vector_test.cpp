#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	string s;
	cout << "enter words followed by .\n";
	while(cin >> s && s!= "."){
		v.push_back(s);
	}
	cout << "You entered: \n";
	for(auto const & itr : v){
		cout << itr <<endl;
	}
	return 0;
}