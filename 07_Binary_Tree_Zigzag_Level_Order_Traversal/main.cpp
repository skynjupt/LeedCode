/*
	https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
	{
		Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

		For example:
		Given binary tree {3,9,20,#,#,15,7},
		    3
		   / \
		  9  20
		    /  \
		   15   7
		return its zigzag level order traversal as:
		[
		  [3],
		  [20,9],
		  [15,7]
		]	
	}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	queue<TreeNode*> q;
	vector< vector<int> > vv;
	vector<int> v;

	q.push(root);
	vector<TreeNode*> vt;
	while(q.size() > 0) {
		TreeNode *t = q.front();
		q.pop();
		vt.push_back(t);
		if(t == NULL) {
			continue;
		}
		q.push(t->left);
		q.push(t->right);
	}	

	int step = 1;
	int j = 0, cnt = 0;
	for(int i = 0; i < vt.size(); i = j) {
		v.clear();
		cnt = 0;

		for(j = i; j < i + step && j < vt.size(); j++) {
			if(vt[j]) {
				v.push_back(vt[j]->val);			
				cnt += 2;
			}
		}
		step = cnt;
		if(v.size() > 0) {
			vv.push_back(v);
		}
	}	

	for(int i = 1; i < vv.size(); i += 2) {
		reverse(vv[i].begin(), vv[i].end());
	}

	return vv;
}

int printMatrix(vector<vector<int> > &vv) {
	cout << "[" << endl;
	for(int i = 0; i < vv.size(); i++) {
		cout << " [";
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j];
			if(j+1 < vv[i].size()) {
				cout << ",";	
			}	
		}
		cout << "]";
		if(i+1 < vv.size()) {
			cout << ",";
		}
		cout << endl;
	}
	cout << "]" << endl;
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

void printTree_level_order(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);
	while( q.size() > 0) {
		TreeNode* n = q.front();
		q.pop();
		if(n == NULL) {
			cout << "# ";
			continue;
		}
		cout << n->val <<" ";
		q.push(n->left);
		q.push(n->right);
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	TreeNode *p;
	vector< vector<int> > vv;

	srandom((unsigned)time(NULL));	

	int t[] = {1,2,3,4,5,0,0};
	p = createTree(t, sizeof(t)/sizeof(int));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);
	
	int a[] = {3, 9, 20, 0, 0, 15, 7};
	p = createTree(a, sizeof(a)/sizeof(a[0]));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);

	int b[] = {1, 2, 3, 4, 5, 0, 0};
	p = createTree(b, sizeof(b)/sizeof(b[0]));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);
	
	int c[] = {1, 0, 2, 3};
	p = createTree(c, sizeof(c)/sizeof(c[0]));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);

	int d[] = {1, 2, 0, 3, 0, 4, 0, 5};
	p = createTree(d, sizeof(d)/sizeof(d[0]));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);

	int e[] = {1, 2, 3, 4, 0, 0, 5};
	p = createTree(e, sizeof(e)/sizeof(e[0]));	
	printTree_level_order(p);
	vv = zigzagLevelOrder(p);
	printMatrix(vv);
	return 0;
}
