/*
	5000
   /    \
 100     6
 / \      / \
200 300   5  3   


- 100 300
- 100 200
- 200 100 300



11 -2 5 6 5 = max

preorder = 5 -2 11 1 6 5 3

0 0 

*/

int maxSum;

int maxRecur(Node *A){
	if(A->left == NULL && A->right == NULL){
		return A->val;
	}
	
	int left = maxRecur(A->left)
	int right = maxRecur(A->right)
	
	int curSumLeft = A->val + left;
	int curSumRight = A->val + right;

	// 1 and 2nd cond
	int curSum = max(A->val , max(curSumRight, curSumLeft));

	// 3rd cond
	int curSumFinal = max(A->val + left + right, curSum)

	if(maxSum < curSumFinal){
		maxSum = curSumFinal;
	}

	return curSum;
}

int main(){
	maxSum = 0;
	
	maxRecur(root);

	cout << maxSum << endl;

}