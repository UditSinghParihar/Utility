#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

vector<int> find_spaces(string line){
	char space = ' ';
	vector<int> index;
	for(int i=0; i<line.length(); ++i){
		if(line[i]==space){
			index.push_back(i);
		}
	}
	return index;
}

vector<double> extract_substring(string line, vector<int> spaces){
	vector<double> substrings;
	for(int i=0; i<9; ++i){
		string word{};
		for(int j=spaces[i]+1; j<spaces[i+1]; ++j){
			word += line[j];
		}
		substrings.push_back(stod(word));
	}
	return substrings;
}

int main(int argc, char const *argv[]){
	if(argc!=3){
		cerr << "Usage: ./file_parser input.g2o output_isam.txt\n";
		return 1;
	}
	ifstream file_read(argv[1]);
	ofstream file_write(argv[2]);
	string line;
	string keyword = "EDGE_SE3:QUAT";
	string covariance2 = " 50 0 0 50 0 100";
	string covariance3 = " 10 0 0 0 0 0 10 0 0 0 0 10 0 0 0 100 0 0 100 0 25";
	vector<double> sub;
	if(file_read.is_open()){
		while(getline(file_read, line)){
			size_t found = line.find(keyword);
			if(found!=std::string::npos){
				sub = extract_substring(line, find_spaces(line));
				Quaternionf q(sub[8],sub[5],sub[6],sub[7]);
				for(int i=0; i<sub.size(); ++i){
					cout << sub[i] << " ";
				}
				auto euler = q.toRotationMatrix().eulerAngles(0, 1, 2);
				cout << endl <<  euler << endl;
				fprintf(stdout, "Final pose_i pose_j x y yaw:%g %g %g %g %g\n",sub[0], sub[1], sub[2], sub[3], euler[2] );
				file_write << "EDGE2 "<<sub[0]<<" "<<sub[1]<<" "<<sub[2]<<" "<<sub[3]<<" "<< euler[2]<<covariance2<< endl ; 
			}
		}
		file_read.close();
		file_write.close();
	}
	else
		cout << "Unable to read file!!\n";
	return 0;
}