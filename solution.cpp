#include <bits/stdc++.h>

using namespace std;

string isLoop(const string& st){
	if(st == "L" || st == "R")
		return "Yes";

	const int thresh = 5;
	int stX = 0, stY = 0;
	int curX = stX, curY = stY;
	bool left=false, right=false, straight=false;


	for(int i=0; i<1000; ++i){
		for(char step:st){
			if(step == 'R'){
				right = true;
				left = false;
				straight = false;
			}
			else if(step == 'L'){
				right = false;
				left = true;
				straight = false;
			}

			else if(step == 'G'){
				if(right){
					
				}
				else if(left){

				}
			}

		}
	}

	return "No";
}


vector<string> doesCircleExist(const vector<string>& inp){
	vector<string> ans{};

	for(auto st:inp){
		string answer = isLoop(st);
		cout << answer << endl;

		ans.push_back(answer);
	}

	return ans;
}


int main(int argc, char const *argv[]){
	vector<string> inp{"RGRG"};

	vector<string> out = doesCircleExist(inp);

	return 0;
}