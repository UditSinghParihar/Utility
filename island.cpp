// #include <bits/stdc++.h>


// using namespace std;

// typedef vector<vector<int>> vvi;


// void printOcean(const vvi &ocean){
// 	for(auto v : ocean){
// 		for(auto cell : v){
// 			printf("%d ", cell);
// 		}
// 		cout << endl;
// 	}

// 	cout << "---\n";
// }


// int checkNbh(int i, int j, const vvi &ocean){
// 	int nrows = ocean.size(), ncols = ocean[1].size();

// 	// Up
// 	if(i-1 >= 0){
// 		if(ocean[i-1][j] > 1){
// 			return ocean[i-1][j];
// 		}
// 	}


// 	// Down
// 	if(i+1 < nrows){
// 		if(ocean[i+1][j] > 1){
// 			return ocean[i+1][j];
// 		}
// 	}


// 	// Right
// 	if(j+1 < ncols){
// 		if(ocean[i][j+1] > 1){
// 			return ocean[i][j+1];
// 		}
// 	}

// 	// Left
// 	if(j-1 >= 0){
// 		if(ocean[i][j-1] > 1){
// 			return ocean[i][j-1];
// 		}
// 	}

// 	// New island
// 	return 1;
// }


// int getIslands(vvi &ocean){
// 	int num;

// 	int nrows = ocean.size(), ncols = ocean[1].size();

// 	int id = 2; 

// 	for(int i=0; i<nrows; ++i){
// 		for(int j=0; j<ncols; ++j){
// 			if(ocean[i][j] == 1){
// 				int res = checkNbh(i, j, ocean);

// 				if(res == 1){
// 					++id;
// 					ocean[i][j] = id;
// 					++num;
// 				}
// 				else{
// 					ocean[i][j] = res;
// 				}
// 			}
// 		}
// 	}
	

// 	return num;
// }


// int main(int argc, char const *argv[]){
// 	// vvi ocean{{1,0,1}, {0,0,1}, {1,0,1}};

// 	vvi ocean{{1, 1, 0, 0, 0},
//       {0, 1, 0, 0, 1},
//       {1, 0, 0, 1, 1},
//       {0, 0, 0, 0, 0},
//       {1, 0, 1, 0, 1} };


// 	printOcean(ocean);
// 	// printf("%zu %zu\n", ocean.size(), ocean[1].size());

// 	int num = getIslands(ocean);

// 	printOcean(ocean);

// 	printf("Number of islands: %d\n", num);

// 	return 0;
// }


#include <bits/stdc++.h>


using namespace std;

typedef vector<vector<int>> vvi;


void printOcean(const vvi &ocean){
	for(auto v : ocean){
		for(auto cell : v){
			printf("%d ", cell);
		}
		cout << endl;
	}

	cout << "---\n";
}


void dfs(vvi &ocean, int i, int j, int id){
	int nrows = ocean.size(), ncols = ocean[0].size();

	if(i >= nrows || j >= ncols || i < 0 || j < 0 || ocean[i][j] == 0 || ocean[i][j] > 1)
		return;

	ocean[i][j] = id;

	dfs(ocean, i+1, j, id);
	dfs(ocean, i-1, j, id);
	dfs(ocean, i, j-1, id);
	dfs(ocean, i, j+1, id);

}


int getIslands(vvi &ocean){
	int num = 0, id = 2;

	int nrows = ocean.size(), ncols = ocean[0].size();

	for(int i=0; i<nrows; ++i){
		for (int j=0; j<ncols; ++j){
			if(ocean[i][j] == 1){
				dfs(ocean, i, j, id);
				++num;
				++id; 

				// printOcean(ocean);
			}
		}
	}

	return num;

}


int main(int argc, char const *argv[]){
		// vvi ocean{{1,0,1}, {0,0,1}, {1,0,1}};

	vvi ocean{{1, 1, 0, 0, 0},
			{0, 1, 0, 0, 1},
			{1, 0, 0, 1, 1},
			{0, 0, 0, 0, 0},
			{1, 0, 1, 0, 1} };

	printOcean(ocean);

	int num = getIslands(ocean);
	printf("Islands: %d\n", num);
	printOcean(ocean);

	return 0;
}



