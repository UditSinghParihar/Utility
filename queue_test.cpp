#include <iostream>
#include<queue>
#include <vector>

using namespace std;

void show_q(queue<int> q){
	queue<int> temp = q;
	cout << "\n--q:\n";
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	cout << "\n--\n";
}

int main(int argc, char const *argv[])
{
	queue<int> q;
	// q.push(10);
	// q.push(20);
	// q.push(456);
	// show_q(q);
	// cout << q.size() << endl;
	// q.pop(); show_q(q);
	// q.push(15); show_q(q);

	vector<int> a;
	a.push_back(4); a.push_back(14); a.push_back(2);
	a.erase(a.begin());
	a.push_back(81); a.erase(a.begin());

	for(auto e : a)
		cout << e << "\n";

	return 0;
}