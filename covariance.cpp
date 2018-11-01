#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define samples 200

using namespace std;

double mean(std::vector<int> v){
	double ans = 0;
	for(int i=0; i<samples; i++)
		ans += v[i];
	return ans/samples;
}

double covariance(std::vector<int> v1, std::vector<int> v2, double x1, double x2){
	double ans = 0;
	for(int i=0; i<samples; i++)
		ans += (v1[i] - x1)*(v2[i] - x2);
	return ans/(samples - 1);
}

int main(int argc, char const *argv[]){
	std::vector<int> v1;
	std::vector<int> v2;
	srand(time(NULL));
	for(int i=0; i<samples; i++){
		v1.push_back(i + (rand()%7));
		v2.push_back(i + 50 + (rand()%4));
	}
	double var1 = covariance(v1,v1, mean(v1), mean(v1));
	double var2 = covariance(v2,v2, mean(v2), mean(v2));
	double cov = covariance(v1, v2, mean(v1), mean(v2));
	fprintf(stdout, "%g\t%g \n%g\t%g\n", var1, cov, cov, var2);
	return 0;
}