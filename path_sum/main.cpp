/*
https://leetcode.com/problems/path-sum/
{
	Path Sum I
	Given a binary tree and a sum, determine if the tree has a root-to-leaf path
	such that adding up all the values along the path equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
	              5
	             / \
	            4   8
	           /   / \
	          11  13  4
	         /  \      \
	        7    2      1
	return true, as there exist a root-to-leaf path 5->4->11->2 
	which sum is 22.

	Path Sum II
	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
	              5
	             / \
	            4   8
	           /   / \
	          11  13  4
	         /  \    / \
	        7    2  5   1
	return
	[
	   [5,4,11,2],
	   [5,8,4,5]
	]
}
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
	if(root == NULL) {
		return false;
	}
	bool ret;
	stack<TreeNode*> st;
	stack<int> sv;
	TreeNode* p;

	st.push(root);
	sv.push(0);
	int s;
	while(!st.empty()) {
		p = st.top();
		st.pop();		
		s = sv.top();
		sv.pop();
			
		if( (s + p->val == sum) && (p->left == NULL) && (p->right == NULL) ) {
			return true;
		}
		
		if(p->right) {
			st.push(p->right);
			sv.push(p->val+s);
		}
		if(p->left) {
			st.push(p->left);
			sv.push(p->val+s);
		}
	}
		
	return false;
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > vv;
	if(root == NULL) {
		return vv;
	}
	vector<int> v;
	stack<TreeNode*> st;
	stack<TreeNode*> spath;
	stack<int> sv;
	TreeNode* p;
	TreeNode* pt;

	st.push(root);
	sv.push(0);
	TreeNode *t = new TreeNode(root->val);
	t->left = NULL;
	spath.push(t);
	int s;
	while(!st.empty()) {
		p = st.top();
		st.pop();		
		s = sv.top();
		sv.pop();
		pt = spath.top();
		spath.pop();	
			
		if( (s + p->val == sum) && (p->left == NULL) && (p->right == NULL) ) {
			v.clear();
			while(pt != NULL) {
				v.push_back(pt->val);
				pt = pt->left;	
			}
			reverse(v.begin(), v.end());
			vv.push_back(v);
			continue;
		}
		
		if(p->right) {
			st.push(p->right);
			sv.push(p->val+s);
			t = new TreeNode(p->right->val);
			t->left = pt;
			spath.push(t);
		}
		if(p->left) {
			st.push(p->left);
			sv.push(p->val+s);
			t = new TreeNode(p->left->val);
			t->left = pt;
			spath.push(t);
		}
	}
	
	return vv;
}


TreeNode *makeTree(int a[],int n) {
	if (n <= 0 ) return NULL;
	TreeNode **tree = new TreeNode*[n];	

	for(int i = 0; i < n; i++) {
		if(a[i] == 0 ) {
			tree[i] = NULL;
			continue;
		}
		tree[i] = new TreeNode(a[i]);
	}
	int pos = 1;
	for(int i = 0; i < n && pos < n; i++) {
		if(tree[i]) {
			tree[i]->left = tree[pos++];
			if(pos < n) {
				tree[i]->right = tree[pos++];
			}
		}
	}
	return tree[0];
}

void printTree_pre_order(TreeNode *root) {
	if(root == NULL) {
		return;
	}
	cout << root->val << " ";
	printTree_pre_order(root->left);
	printTree_pre_order(root->right);
}

void printvv(vector<vector<int> >& vv) {
	int n = vv.size();
	for(int i = 0; i < n; i++) {
		cout << "[ ";
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << " ";	
		}
		cout << "]" << endl;;
	}
}

int main(int argc, char *argv[]) {
	TreeNode *t;
//	int a[] = {5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 5, 1};
	int a[] = {1, 0, 0};
	t = makeTree(a, sizeof(a)/sizeof(a[0]));
//	printTree_pre_order(t);
//	cout << hasPathSum(t, 22);
	
//	vector<vector<int> > vv = pathSum(t, 22);	
	vector<vector<int> > vv = pathSum(t, 1);	
	printvv(vv);
	return 0;
}
