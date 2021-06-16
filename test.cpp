// #include <iostream>
// #include <string>
// using namespace std;
  
// template <typename T>
// // A function to implement bubble sort
// void bubbleSort(T a[], int n) {
//     for (int i = 0; i < n - 1; i++)
//         for (int j = n - 1; i < j; j--)
//             if (a[j] < a[j - 1])
  
//         // calls template function
//         swap(a[j], a[j - 1]);
// }
  
// template <typename X>
  
// // A Function to perform swapping
// void swap(X &a, X &b) {
//     X temp = a;
//     a = b;
//     b = temp;
// }

// template <typename Y>

// Y divide(Y a, Y b){
//     Y result = a/b;
//     return result;
// }

// // Driver Code
// int main() {
//     int a[5] = {10, 50, 30, 40, 20};
//     int n = sizeof(a) / sizeof(a[0]);
   
//     char st[5] = {'z', 'e', 'b', 'a' ,'d'};
//     int n_c = sizeof(st) / sizeof(st[0]);
//     // calls template function 
//     bubbleSort<int>(a, 5);
//     bubbleSort<char>(st, 5);
  
//     cout << " Sorted array : ";
//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
//     cout << endl;
//     for (int i =0 ; i < n_c; i++)
//          cout << st[i] << " ";

//     cout << endl << "integer:- " <<divide<int>(5.0,2.0) << endl;
//     cout << "double:- " << divide<double>(5,2) << endl;
//   return 0;
// }

// #include <string>
#include <bits/stdc++.h>

using namespace std;

// string findDigitsInBinary(int A) {
// 	string ret = "";
	
// 	int qt = A, rem=0;
// 	while(qt != 0){
// 		if(qt<2){
// 			rem = qt;
// 			qt = 0;

// 			ret += to_string(rem);
// 			continue;
// 		}

// 		rem = qt - (int(qt/2)*2);
// 		qt = int(qt/2);

// 		ret += to_string(rem);		
// 	}
	
// 	int i=0, j=ret.size()-1;
	
// 	while(j>i){
// 		char temp = ret[i];
// 		ret[i] = ret[j];
// 		ret[j] = temp;
		
// 		i++;
// 		j--;
// 	}

// 	cout << ret << endl;
// 	return ret;
// }
  


// int main(int argc, char const *argv[]){
// 	findDigitsInBinary(6);
// 	return 0;
// }

// int main(int argc, char const *argv[]){
// 	vector<int> numbs;

// 	for(int i=0; i<10; ++i)
// 		numbs.push_back(pow(i, 2));


// 	for(auto e:numbs)
// 		printf("%d\n", e);

// 	numbs.erase(numbs.begin(), numbs.begin()+2);

// 	for(auto e:numbs)
// 		printf("%d\n", e);

// 	// printf("%d %d\n", numbs[5], numbs.at(5));


// 	return 0;
// }

// bool wayToSort(int a, int b){
// 	if(a>b)
// 		return true;
// 	else
// 		return false;
// }


// int main(int argc, char const *argv[]){
// 	vector<int> num{2, -1, 100, 9, 5, 80, 50, 1};

// 	auto res = find(num.begin(), num.end(), 80);
// 	cout << *res << " " << res-num.begin() << endl;
// 	if(res != num.end())
// 		printf("Found at %ld %d\n", res-num.begin(), num[res-num.begin()]);
// 	else
// 		printf("Not found.\n");

// 	// sort(num.begin(), num.end(), wayToSort);

// 	// for(auto e : num){
// 	// 	printf("%d ", e);
// 	// }
// 	// cout << endl;

// 	return 0;
// }

// void threadFun(void){
// 	for(int i=0; i<10000; ++i)
// 		printf("Inside Thread.\n");
// }


// int main(int argc, char const *argv[]){
// 	thread th(threadFun);

// 	for(int i=0; i<10000; ++i)
// 		printf("Inside main.\n");

// 	th.join();

// 	printf("Exiting main.\n");


// 	return 0;
// }

// void print(const vector<int> &v){
// 	for(auto e : v)
// 		printf("%d ", e);
// 	cout << endl;
// }


// int main(int argc, char const *argv[]){
// 	vector<int> v{2, -1, 100, 90, 40, 8};
// 	print(v);

// 	// rotate(v.begin(), v.begin()+1, v.end());
// 	// print(v);


// 	// printf("%d %d\n", *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));


// 	// int a=4, b=20;

// 	// printf("%d %d\n", max(a, b), min(a, b));

// 	for_each(v.begin(), v.end(), [](int &x){x *= 2;});
// 	print(v);

// 	return 0;
// }


// int main(int argc, char const *argv[]){
// 	string st = "localization";

// 	string res{};

// 	res += st[0];
// 	res += to_string(st.size());
// 	res += st[st.size()-1];

// 	float a = 4.5;
// 	// cout << res << endl;
// 	printf("%s %f\n", res.c_str(), ceil(a));

// 	return 0;
// }


// void fun(int x){
// 	printf("%d\n", x);

// 	return;
// }


// int main(int argc, char const *argv[]){
// 	int i = 10;
// 	fun(i);

// 	return 0;
// }


// vector<int> pascal(int k){
// 	if(k == 0)
// 		return vector<int> {1};
// 	if(k == 1)
// 		return vector<int> {1, 1};

// 	vector<int> res{1};

// 	for(int j=2; j<=k; ++j){
// 		for(int i=1; i<j-1; ++i){

// 		}
// 	}

// 	res.push_back(1);

// 	return res;
// }


// int main(int argc, char const *argv[]){
// 	int k = 2;

// 	auto v = pascal(k);
// 	for(auto e : v)
// 		printf("%d ", e);
// 	cout << endl;

// 	return 0;
// }


// int main(int argc, char const *argv[]){
// 	unordered_map<int, int> um{};

// 	um.insert(make_pair(2, 30));
// 	um.insert(pair<int, int>(4, 50));
// 	um[8] = 90;

// 	for(auto it=um.begin(); it!=um.end(); ++it){
// 		printf("%d : %d\n", it->first, it->second);
// 	}


// 	return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int num = 0;
	
//     cin >> num;
	
//     vector<int> inp(num, 0);
	
//     for(int i=0; i<num; ++i){
//         int temp{};
//         cin >> temp;
//         inp[i] = temp;
//     }
	
//     int maxi = *max_element(inp.begin(), inp.end());
	
//     vector<int> fact{1, 1};
	
//     for(int i=2; i<=maxi; ++i){
//         int cur = i*fact[i-1];
//         fact.push_back(cur);
//     }

//     for(int i=0; i<inp.size(); ++i){
//         cout << fact[inp[i]] << endl;
		
//     }


// 	return 0;
// }


// int main(int argc, char const *argv[]){
// 	int a = 2, b = 3, c = 3;

// 	int num = int(pow(a, b))%c;
// 	printf("%d\n", num);


// 	return 0;
// }

// int main(int argc, char const *argv[]){
// 	string st1 = "123", st2 = "423";

// 	cout << st2.compare(st1) << endl;


// 	return 0;
// }

// typedef vector<int> vi;
// typedef vector<vi> vvi;


// void printMat(const vvi &M){
// 	for(auto r : M){
// 		for(auto e : r){
// 			printf("%d ", e);
// 		}
// 		cout << endl;
// 	}
// 	cout << "\n---\n";
// }


// void mul(const vvi &A, const vvi &B, vvi &C){
// 	int rows = C.size(), cols = C[0].size();
// 	printf("%d %d\n", rows, cols);

// 	for(int i=0; i<rows; ++i){
// 		for(int j=0; j<cols; ++j){
// 			for(int k=0; k<rows; ++k){
// 				C[i][j] += A[i][k] * B[k][j];
// 			}
// 		}
// 	}

// }


// int main(){
// 	vvi A = {{1, 2, 3}, {1, 0, 0}, {3, 1, 1}};
// 	vvi B = {{1, 0, 1}, {2, 1, 1}, {1, 1, 2}};
// 	vvi C(A.size(), vi(A[0].size(), 0));

// 	mul(A, B, C);

// 	printMat(A);
// 	printMat(B);

// 	printMat(C);

// 	return 0;
// }


// typedef pair<int, int> pii;
// typedef vector<pii> vpii;


// int main(int argc, char const *argv[]){
// 	vpii data{pii(2, 4), pii(5, 10), pii(6, 12)};

// 	for(auto &p : data){
// 		printf("%d %d\n", p.first, p.second);
// 	}

// 	pii q(4, 0);




// 	return 0;
// }

// int main(int argc, char const *argv[]){
// 	vector<int> inp{-3, 2, 1, 90, 4, -9};
// 	auto maxIt = max_element(inp.begin(), inp.end()), minIt = min_element(inp.begin(), inp.end());
// 	// auto minIt = min_element(inp.begin(), inp.end());
// 	int maxIdx = maxIt - inp.begin();
// 	int minIdx = minIt - inp.begin();


// 	printf("Max: %d at %d and Min: %d at %d \n", *maxIt, maxIdx, *minIt, minIdx);


// 	return 0;
// }


// void printMat(const vector<vector<int>> &A){
// 	for(int i=0; i<A.size(); ++i){
// 		for(int j=0; j<A[0].size(); ++j){
// 			printf("%2d ", A[i][j]);
// 		}
// 		cout << endl;
// 	}
// 	cout << "\n--\n";
// }


// int main(int argc, char const *argv[]){
// 	int m = 3, n = 5;
// 	vector<vector<int>> A(m, vector<int>(n));
// 	vector<vector<int>> B(n, vector<int>(m));

// 	int val = 10;
// 	for(int i=0; i<m; ++i)
// 		for(int j=0; j<n; ++j)
// 			A[i][j] = val++;


// 	printMat(A);

// 	for(int i=0; i<m; ++i){
// 		for(int j=i; j<n; ++j){
// 			// int temp = A[i][j];
// 			// A[i][j] = A[j][i];
// 			// A[j][i] = temp;

// 			B[j][i] = A[i][j];
				
// 			if(i<n && j<m)	
// 				B[i][j] = A[j][i];
// 		}
// 	}

// 	printMat(B);
	
// 	return 0;
// }

// int main(int argc, char const *argv[]){
// 	int num = 234;
// 	string st = to_string(num);

// 	printf("%s %d\n", st.c_str(), num);

// 	vector<int> inp{};

// 	cout << int(st[0]-'0') << endl;
	
// 	// for(int i=0; i<st.size(); ++i){
// 	// 	cout << stoi()<< endl;
// 	// }

// 	return 0;
// }


// int main(int argc, char const *argv[]){
// 	vector<int> inp{1,22,73,24,5};

// 	sort(inp.begin(), inp.end());

// 	int num = 22;
// 	auto it = binary_search(inp.begin(), inp.end(), num);

// 	if(it == True)
// 		printf("%d at %d\n", num, );
// 	else
// 		printf("%d not found.\n", num);

// 	// int i=1;
// 	// if(find(inp.begin(), inp.begin()+i, inp[i]) == inp.end())
// 	// 	printf("yes\n");
// 	// else
// 	// 	printf("no\n");
// 	// string st = "123";

// 	// vector<int> inp{};

// 	// for(auto e : st)
// 	// 	inp.push_back(int(e-'0'));
	
// 	// int n = inp.size();

// 	// for(int sz=1; sz<=n; ++sz){
// 	// 	for(int st=0; st<=n-sz; ++st){
// 	// 		int prod = 1;
// 	// 		for(int j=st; j<st+sz; ++j){
// 	// 			// printf("%d ", inp[j]);
// 	// 			prod *= inp[j];
// 	// 		}
// 	// 		cout << prod << endl;
// 	// 	}
// 	// }


// 	return 0;
// }


// struct Node{
// 	Node *left;
// 	Node *right;
// 	int val;

// 	Node(int data=0) {
// 		val = data;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// class BST{
// public:
// 	Node *root;

// public:
// 	BST(){
// 		root = NULL;
// 	}

// 	bool isEmpty(){
// 		if(root == NULL)
// 			return true;
// 		else
// 			return false;
// 	}

// 	void insert(int data){
// 		Node *p = new Node(data);

// 		if(isEmpty() == true){
// 			root = p;
// 		}
// 		else{
// 			Node *itr = root, *parent = root;

// 			while(itr != NULL){
// 				parent = itr;

// 				if(itr->val < data){
// 					itr = itr->right;
// 				}
// 				else{
// 					itr = itr->left;
// 				}

// 			}

// 			if(parent->val < data){
// 				parent->right = p;
// 			}
// 			else{
// 				parent->left = p;
// 			}
// 		}

// 	}

// 	void preOrderRecur(Node *ptr){
// 		if(ptr != NULL){
// 			printf("%d ", ptr->val);

// 			preOrderRecur(ptr->left);
// 			preOrderRecur(ptr->right);
// 		}
// 	}

// 	void preOrderTravese(){
// 		preOrderRecur(root);
// 		cout << endl;
// 	}
	
// };

// vector<int> inp;

// void preorderTree(Node *A){
// 	if(A != NULL){
// 		inp.push_back(A->val);
		
// 		preorderTree(A->left);
// 		preorderTree(A->right);
// 	}
// }

// int main(int argc, char const *argv[]){
// 	// Node *ptr = new Node(42);
// 	// printf("%d\n", ptr->val);	

// 	BST bst;

// 	bst.insert(8);
// 	bst.insert(2);
// 	bst.insert(9);
// 	bst.insert(11);
// 	bst.insert(4);
// 	bst.insert(3);
// 	bst.insert(5);
// 	bst.insert(20);
// 	bst.insert(7);
// 	bst.insert(10);
// 	bst.insert(21);

// 	bst.preOrderTravese();

// 	preorderTree(bst.root);

// 	for(auto e : inp)
// 		printf("%d ", e);
// 	cout << endl;

// 	return 0;
// }


// int main(int argc, char const *argv[]){
// 	string st = "HeLLIo";

// 	transform(st.begin(), st.end(), st.begin(), ::tolower);

// 	for(auto e : st)
// 		printf("%c ", e);
// 	cout << endl;

// 	// for(auto e : st){
// 	// 	// printf("%c ", tolower(e));
// 	// 	cout << (char)tolower(e) << " ";
// 	// }
// 	// cout << endl;

// 	return 0;
// }

int main(int argc, char const *argv[]){
	unordered_map<string, string> mp = {{"Lose yourself", "Eminem"}, {"Ocean eyes", "B. Eillish"}};
	pair<int, int> *p1 = new pair<int, int>(2, 3);
	printf("Pair: %d and %d\n", p1->first, p1->second);
	delete p1;

	mp.insert(make_pair("Hello", "Sia"));

	for(auto it=mp.begin(); it!=mp.end(); ++it){
		printf("%s by %s\n", it->first.c_str(), it->second.c_str());
	}

	return 0;
}