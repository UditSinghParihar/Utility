#include <iostream>
#include <vector>
using namespace std;

void print(const std::vector<int>& v){
	for(int i=0; i<v.size(); ++i) cout << v[i] << endl;
}

vector<int> merge(const vector<int>&a, const vector<int>&b, const vector<int>&c){
	int length = a.size() + b.size() + c.size();
	vector<int> result;
	for(int i=0; i<length; ++i){
		if(i<a.size()) result.push_back(a[i]);
		else if(i<(a.size()+b.size())) result.push_back(b[i]);
		else result.push_back(c[i]);
	}
	return result;
}

vector<int> quicksort(const vector<int>& a){
	if(a.size() <= 1) return a;

	int pivot = a[int(a.size())/2];
	vector<int> left, right, middle;

	for(int i=0; i<a.size(); ++i){
		if(a[i]<pivot) left.push_back(a[i]);
		else if(a[i]>pivot) right.push_back(a[i]);
		else middle.push_back(a[i]);
	}

	return merge(quicksort(left), middle, quicksort(right));
}

int main(int argc, char const *argv[]){
	vector<int> a{3,6,8,10,1,2,1};
	vector<int>b = quicksort(a);
	// print(a);
	print(b);
	return 0;
}