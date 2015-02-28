#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode *root, int h, int &flag) {
	if(!root->left && !root->right) {
		return h;
	}

	int left_h = h;
	int right_h = h;
	if(root->left && flag) left_h = dfs(root->left, h+1, flag);
	if(root->right && flag) right_h = dfs(root->right, h+1, flag);

	int t = left_h > right_h ? (left_h-right_h) : (right_h-left_h);
	if(t > 1) {
		flag = 0;	
	}

	return left_h > right_h ? left_h : right_h;
}

bool isBalanced(TreeNode *root) {
	if(root == NULL) {
		return true;
	}

	int flag = 1;
	dfs(root, 1, flag);
	return flag;
}

TreeNode *createTree(int a[], int n) {
	vector<TreeNode*> v;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			v.push_back(NULL);
			continue;
		}
		TreeNode *t = new TreeNode(a[i]);
		v.push_back(t);
	}	

	int j = 1;
	for(int i = 0; i < n && j < n; i++) {
		if(v[i] != NULL) {
			v[i]->left = v[j++];
			if(j < n) {
				v[i]->right = v[j++];
			}
		}
	}

	return v[0];
}

int main(int argc, char *argv[]) {
	int a[] = { 3, 2, 4, 5, 7, 0, 0, 8, 9, 0, 0};	
	TreeNode *t = createTree(a, sizeof(a)/sizeof(a[0]));
	cout << isBalanced(t) << endl;

	int b[] = { 3, 2, 4, 5, 7, 8, 0, 8, 9, 0, 0};	
	t = createTree(b, sizeof(b)/sizeof(b[0]));
	cout << isBalanced(t) << endl;

	return 0;
}
