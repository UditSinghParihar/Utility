#include <iostream>
#include <vector>

using namespace std;

class vector_class{
private:
	const vector<int>& list;

public:
	vector_class(const vector<int>& arg_list): list{arg_list}{
		// this->list = arg_list;
	};
};

int main(int argc, char const *argv[]){
	vector<int> list{1, 2, 3, 4};
	vector_class container{list};
	return 0;
}