#include <bits/stdc++.h>

using namespace std;


// void getFib(vector<float> &vFib){
// 	for(int i=2; i<vFib.size(); ++i)
// 		vFib[i] = vFib[i-1] + vFib[i-2];
// }


// int main(int argc, char const *argv[]){
// 	const int n = 50;
// 	vector<float> vFib(n);

// 	vFib[0] = 1;
// 	vFib[1] = 1;

// 	getFib(vFib);

// 	printf("Fibonacci %d is %.f\n", n, vFib[n-1]);

// 	return 0;
// }

template<int N, typename T = int>
struct fibonacci {
    static constexpr T value = fibonacci<N-1,T>::value + fibonacci<N-2,T>::value;
};

template<typename T>
struct fibonacci<1,T> {
    static constexpr T value = 1;
};

template<typename T>
struct fibonacci<0,T> {
    static constexpr T value = 0;
};


int main(int argc, char const *argv[]){
	const int n = 100;
	cout << "Fibonacci " << n << " is " << fibonacci<n, unsigned long int>::value << endl;

	return 0;
}