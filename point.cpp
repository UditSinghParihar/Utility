// #include <iostream>
// #include <cmath>

// using namespace std;

// class Point2d{
// private:
// 	double m_x;
// 	double m_y;
// public:
// 	Point2d(double x=0.0, double y=0.0):m_x{x}, m_y{y}{};
// 	void print(void){
// 		fprintf(stdout, "Point2d(%g, %g);\n", m_x, m_y);
// 	}
// 	double distanceTo(const Point2d& obj)const{
// 		return sqrt(pow(m_x-obj.m_x, 2) + pow(m_y-obj.m_y, 2));
// 	}
// 	friend double distanceFrom(const Point2d& obj1, const Point2d& obj2);
// };

// double distanceFrom(const Point2d& obj1, const Point2d& obj2){
// 	return sqrt(pow(obj1.m_x-obj2.m_x, 2) + pow(obj1.m_y-obj2.m_y, 2));
// }

// int main(int argc, char const *argv[]){
// 	Point2d first;
// 	Point2d second(3.0, 4.0);
// 	first.print();
// 	second.print();
// 	cout << "Distance between two points: "<< first.distanceTo(second) << endl;
// 	cout << "Distance between function: " << distanceFrom(first, second) << endl;
// 	return 0;
// }

#include <bits/stdc++.h>

using namespace std;

// struct Something{
// 	int x{}, y{}, z{};
// };

// int main(int argc, char const *argv[]){
// 	Something* smthptr{};
// 	Something smth{};

// 	int* iptr{};
// 	char* cptr{};

// 	// cout << sizeof(smthptr) << endl; 
// 	printf("%zu %zu %zu %zu\n", sizeof(smthptr), sizeof(smth), sizeof(iptr), sizeof(cptr));

// 	return 0;
// }


// int solve(const vector<int> &v, int B){
// 	for(auto i : v)
// 		for(auto j : v)
// 			if(i-j == B && i!=j){
// 				cout << i << " " << j << endl;
// 				return 1;
// 			}

// 	return 0;
// }


// int solve2(vector<int> &A, int B){
//     unordered_set <int> us;

//     if(B == 0)
//     	return 0;
    
//     for(auto e : A)
//         us.insert(e);
        
//     for(auto e : A)
//         if(us.find(e+B) != us.end())
//             return 1;
    
//     return 0;
    
// }


// int main(int argc, char const *argv[]){
// 	vector<int> v{5, 10, 3, 2, 50, 80};
// 	int B = 0;

// 	cout << solve2(v, B) << endl;

// 	return 0;
// }



struct Node{
	int data;
	Node *next;
	
};


int main(int argc, char const *argv[]){
	vector<int> v{2, 11, 9, 20, 5};

	Node *head = nullptr;
	Node *end = nullptr;

	head = new Node();
	head->data = v[0];
	head->next = nullptr;

	end = head;

	for(int i=1; i<v.size(); ++i){
		end->next = new Node();
		end->next->data = v[i];
		end->next->next = nullptr;

		end = end->next;
	}

	Node *itr = head;
	while(itr != nullptr){
		printf("%d ", itr->data);
		itr = itr->next;
	}
	printf("\n");
	
	return 0;
}