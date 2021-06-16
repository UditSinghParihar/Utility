#include <bits/stdc++.h>

using namespace std;


int findCount(const vector<int> &A, int B, bool left){
	int low=0, high=A.size()-1;
	int pos=-1;

	while(low <= high){
		int mid = low + (high-low)/2;

		if(A[mid] == B){
			pos=mid;

			if(left)
				high = mid-1;
			else
				low = mid+1;
		}

		else if(A[mid] > B){
			high = mid-1;
		}

		else{
			low = mid+1;
		}
	}
	return pos;
}


int main(int argc, char const *argv[]){
	vector<int> vec{5, 7, 7, 8, 8, 10};
	int trg = 8;
	string str = "Hello";
	cout << str.size() << endl;
	printf("%zu\n", str.size());
	return 0;

	printf("%d %f\n", 5, 5.5);

	int id = findCount(vec, trg, false);
	cout << id << endl;


	return 0;
}