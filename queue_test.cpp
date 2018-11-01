#include <iostream>
#include<queue>

using namespace std;

void show_q(queue<int> q){
	queue<int> temp = q;
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
}

int main(int argc, char const *argv[])
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(456);
	show_q(q);
	return 0;
}