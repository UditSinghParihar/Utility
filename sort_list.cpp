#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <dirent.h>

using namespace std;

int strip(string str){
	int index = 5;
	string result{};
	while(str[index] != '.'){
		result += str[index];
		index++;
	}
	return stoi(result);
}



int main(int argc, char const *argv[]){
	vector<int> list;
	string str;
	if(argc != 2){
		cout << "Enter a Directory\n";
		return 1;
	}
	//ifstream file {argv[1]};
	string keyword = "cloud";
	DIR* dirp = opendir(argv[1]);
	dirent* dp;
	while((dp = readdir(dirp)) != NULL){
		if(string(dp->d_name).find(keyword) != std::string::npos)
			list.push_back(strip(dp->d_name));
	}
	closedir(dirp);
	sort(list.begin(), list.end());
	for(int i=0; i<list.size(); ++i)
		cout <<"cloud"<<list[i]<<".pcd" << endl;
	return 0;
}