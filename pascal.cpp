#include <bits/stdc++.h>

using namespace std;


vector<int> printPascal(const int k){
	if(k == 0)
		return vector<int> {1};
	else if(k==1)
		return vector<int> {1, 1};
	else{
		vector<int> prev{1, 1};

		for(int i=2; i<=k; ++i){
			vector<int> res{1};

			for(int j=1; j<=i-1; ++j){
				res.push_back(prev[j-1] + prev[j]);
			}

			res.push_back(1);

			prev = res;
		}
		
		return prev;
	}
}



int main(){
	const int k = 5;

	auto res = printPascal(k);

	for(auto e : res)
		printf("%d ", e);
	cout << endl;

	return 0;
}