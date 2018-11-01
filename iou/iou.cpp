#include <iostream>
#include <fstream>

#define n_images 4
#define n_cat 5

using namespace std;

int true_positive(int gt[][n_images], int result[][n_images], int row){
	int ans = 0;
	for(int i=0; i<n_images; i++){
		if(gt[row][i] == result[row][i])
			ans++;
	}
	return ans;
}

int false_positive(int result[][n_images], int row){
	int ans = 0;
	for(int i=0; i<n_cat; i++){
		if(i == row)
			continue;
		for(int j=0; j<n_images; j++){
			if(row + 1 == result[i][j])
				ans ++; 
		}	
	}
	return ans;
}
int main(int argc, char const *argv[]){
	int gt[n_cat][n_images]{};
	int result[n_cat][n_images]{};
	ifstream file1 {"ground_truth.txt"};
	ifstream file2 {"result.txt"};
	for(int i=0; i<n_cat; i++){
		for(int j=0; j<n_images; j++){
			file1 >> gt[i][j];
			file2 >> result[i][j];
		}
	}

	for(int row=0; row<n_cat; row++){
		int tp = true_positive(gt, result, row );
		int fn = n_images - tp;
		int fp = false_positive(result, row);
		float answer = (float(tp)/(tp + fn + fp)) * 100;
		cout << "For category " << row +1 << endl;
		cout << "True positive: "<< tp << '\t' << "False negative: "<< fn << '\t' << "False positive: " << fp << '\t' << "IOU accuracy: " << answer <<"%"<< endl;
	}
	return 0;
}