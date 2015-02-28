#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#if 0
int traversal(TreeNode *root, int sum) {
	if(root) {
		sum += root->val;
		if(root->left && root->right) {
			if(root->left->val > root->right->val) {
				sum = traversal(root->left, sum);
			} else {
				sum = traversal(root->right, sum);
			}	
		} else if(root->left) {
			sum = traversal(root->left, sum);
		} else if(root->right) {
			sum = traversal(root->right, sum);
		}
	}

	return sum;
}

int maxPathSum(TreeNode *root) {
	return traversal(root, 0);	
}
#endif

/*
 * Wrong Answer
 * Input: 	{-3}
 * Output: 	0
 * Expected: 	-3
 */

int max_path_sum = 0; 

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int traversal(TreeNode *root) {
	if(!root) {
		return 0;	
	}
#if 0	
	int left_max = 0, right_max = 0;
#else
	int left_max, right_max;
	if(root->val < 0) {
		left_max = right_max = root->val;
	} else {
		left_max = right_max = 0;
	}
#endif
	if(root->left) left_max = traversal(root->left); 
	if(root->right) right_max = traversal(root->right);

	// merge to get max
#if 0
	int ret = 0;
	if(left_max > right_max) {
		ret = left_max + root->val;	
		if(left_max > root->val) {
			if(left_max > max_path_sum) max_path_sum = left_max;	
		} else {
			if(root->val > max_path_sum) max_path_sum = root->val;
		}
	} else {
		ret = right_max + root->val;
		if(right_max > root->val) {
			if(right_max > max_path_sum) max_path_sum = right_max;	
		} else {
			if(root->val > max_path_sum) max_path_sum = root->val;
		}
	}

	if(root->val > ret) ret = root->val;
	if(ret > max_path_sum) max_path_sum = ret;
	if(left_max + right_max + root->val > max_path_sum) 
		max_path_sum = left_max + right_max + root->val;

	return ret;
#else
	int tmp = root->val;
	tmp = MAX(tmp, tmp+left_max);
	tmp = MAX(tmp, tmp+right_max);
	max_path_sum = MAX(max_path_sum, tmp);
	return MAX(root->val, root->val+MAX(left_max, right_max));	
#endif
}

int maxPathSum(TreeNode *root) {
	max_path_sum = INT_MIN; 
	traversal(root);	
	return max_path_sum;
}

TreeNode* createTree(int a[], int n)
{
	if (n<=0) return NULL;

	TreeNode **tree = new TreeNode*[n];

	for(int i=0; i<n; i++) {
		if(a[i] == 0) {
			tree[i] = NULL;
			continue;
		}
		tree[i] = new TreeNode(a[i]);
	}
	int pos = 1;
	for(int i=0; i<n && pos<n; i++) {
		if(tree[i]) {
			tree[i]->left = tree[pos++];
			if (pos<n) {
				tree[i]->right = tree[pos++];
			}
		}	
	}
	return tree[0];
}

int main(int argc, char *argv[])
{
	TreeNode *p;

	int t[] = {1,2,3,4,5,0,0};
	p = createTree(t, sizeof(t)/sizeof(int));	
	cout << maxPathSum(p) << endl;
	
	int a[] = {3, 9, 20, 0, 0, 15, 7};
	p = createTree(a, sizeof(a)/sizeof(a[0]));	
	cout << maxPathSum(p) << endl;

	int b[] = {1, 2, 3, 4, 5, 0, 0};
	p = createTree(b, sizeof(b)/sizeof(b[0]));	
	cout << maxPathSum(p) << endl;
	
	int c[] = {1, 0, 2, 3};
	p = createTree(c, sizeof(c)/sizeof(c[0]));	
	cout << maxPathSum(p) << endl;

	int d[] = {1, 2, 0, 3, 0, 4, 0, 5};
	p = createTree(d, sizeof(d)/sizeof(d[0]));	
	cout << maxPathSum(p) << endl;

	int e[] = {1, 2, 3, 4, 0, 0, 5};
	p = createTree(e, sizeof(e)/sizeof(e[0]));	
	cout << maxPathSum(p) << endl;

	int f[] = {-3};
	p = createTree(f, sizeof(f)/sizeof(f[0]));	
	cout << maxPathSum(p) << endl;

	int g[] = {1, -2, -3, 1, 3, -2, 0, -1};
	p = createTree(g, sizeof(g)/sizeof(g[0]));	
	cout << maxPathSum(p) << endl;

	return 0;
}
