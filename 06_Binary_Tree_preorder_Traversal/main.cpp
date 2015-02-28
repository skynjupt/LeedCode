#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> traversal(TreeNode *root, vector<int> v);

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> v;
	v = traversal(root, v);
	return v;
}
vector<int> traversal(TreeNode *root, vector<int> v) {

	if(root) {
		v.push_back(root->val);
	}

	if(root && root->left) {
		v = traversal(root->left, v);
	}

	if(root && root->right) {
		v = traversal(root->right, v);
	}

	return v;
}

vector<int> preorderTraversal2(TreeNode *root) {
	stack<TreeNode *> s;
	vector<int> v;
	TreeNode *t;
	
	s.push(root);
	while(!s.empty()) {
		t = s.top();
		s.pop();
		if(t) {
			v.push_back(t->val);
			if(t->right) s.push(t->right);
			if(t->left) s.push(t->left);
		}
	}

	return v;
		
}
void printTree(vector<int> v) {
	cout << "[";
	for(int i = 0; i < v.size(); i++) {
		cout << v[i];
		if(i+1 < v.size()) {
			cout << ",";
		} 
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
	vector<int> v;

	int t[] = {1,2,3,4,5,0,0};
	p = createTree(t, sizeof(t)/sizeof(int));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);

	int a[] = {3, 9, 20, 0, 0, 15, 7};
	p = createTree(a, sizeof(a)/sizeof(a[0]));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);

	int b[] = {1, 2, 3, 4, 5, 0, 0};
	p = createTree(b, sizeof(b)/sizeof(b[0]));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);
	
	int c[] = {1, 0, 2, 3};
	p = createTree(c, sizeof(c)/sizeof(c[0]));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);
	
	int d[] = {1, 2, 0, 3, 0, 4, 0, 5};
	p = createTree(d, sizeof(d)/sizeof(d[0]));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);

	int e[] = {1, 2, 3, 4, 0, 0, 5};
	p = createTree(e, sizeof(e)/sizeof(e[0]));	
	v = preorderTraversal(p);
	printTree(v);
	v = preorderTraversal2(p);
	printTree(v);
	
	return 0;
}
