#include <bits/stdc++.h>
using namespace std;


vector<int> sieve(int A) {
	vector<int> res(A+1);
	
	auto isPrime = [](int B){
		int result = 1;
		
		if(B == 1)
			return 0;
		if(B == 2)
			return 1;
		
		for(int i=2; i<sqrt(B)+1; ++i){
			if(B%i == 0){
				result = 0;
			}
		}
		return result;
	};
	
	res[0] = 1;
	res[1] = 1;
	for(int i=2; i<A+1; ++i){
		if(res[i] == 0){
			if(isPrime(i) == 1){
				for(int j=i; j<A+1; ++j)
					res[j*i] = 1;
				
			}
			else{
				res[i] = 1;
			}
		}
	}
	
	vector<int> filter{};
	for(int i=0; i<res.size(); ++i){
		if(res[i] == 0){
			filter.push_back(i);
		}
	}
	
	return filter;
}


int main(int argc, char const *argv[]){
	auto primes = sieve(36);
	// for(auto e:primes)
	// 	cout << e << " ";

	return 0;
}