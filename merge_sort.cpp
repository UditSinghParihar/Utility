#include <iostream>
#include <vector>


using namespace std;


void merge(std::vector<int> &v, int st, int end){
	std::vector<int> tmp(end-st+1);

	int mid = (st+end)/2;
	int i=st, j=mid+1, k=0;

	while(i<=mid && j<=end){
		if(v[i] <= v[j]){
			tmp[k] = v[i];
			++i;
			++k;
		}
		else{
			tmp[k] = v[j];
			++j;
			++k;
		}
	}

	while(i<=mid){
		tmp[k] = v[i];
		++i;
		++k;
	}

	while(j<=end){
		tmp[k] = v[j];
		++j;
		++k;
	}

	for(int i=st; i<=end; ++i){
		v[i] = tmp[i-st];
	}

}


void mergeSort(std::vector<int> &v, int st, int end){
	if(st<end){
		int mid = (st+end)/2;

		mergeSort(v, st, mid);
		mergeSort(v, mid+1, end);
		merge(v, st, end);
	}

}	


int main(int argc, char const *argv[]){
	std::vector<int> v{12, 9, 45, 8, 2, 78, 13, 100};

	for(int i=0; i<v.size(); ++i){
		printf("%d ", v[i]);
	}
	cout << endl;

	int st=0, end=v.size();
	mergeSort(v, st, end);

	for(int i=0; i<v.size(); ++i){
		printf("%d ", v[i]);
	}
	cout << endl;

	return 0;
}