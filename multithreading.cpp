#include <iostream>
#include <pthread.h>

using namespace std;

void *fun1(void *id){
	while(true)
		cout << "Inside fun1 with id: " << *((int*) id) << endl;
	pthread_exit(NULL);
}

void *fun2(void *id){
	while(true)
		cout << "Inside fun2 with id: " << *((int*) id) << endl;
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t thread1, thread2;
	int id1 = 100, id2 = 200;
	pthread_create(&thread1, NULL, fun1, &id1);
	pthread_create(&thread2, NULL, fun2, &id2);
	pthread_exit(NULL);
	return 0;
}