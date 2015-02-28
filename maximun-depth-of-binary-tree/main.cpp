#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
int maxDepth(TreeNode *root) {
	if(root == NULL) {
		return 0;
	}

	int left_depth = maxDepth(root->left);
	int right_depth = maxDepth(root->right);
	return left_depth>right_depth ? left_depth+1 : right_depth+1;
}
#endif

int maxDepth(TreeNode *root) {
	if(root == NULL) {
		return 0;
	}

	int maxDepth = 0, d = 0;
	stack<TreeNode*> st;
	stack<int> dp;
	TreeNode* p;

	st.push(root);
	dp.push(1);
	while(!st.empty()) {
		p = st.top();
		st.pop();	
		d = dp.top();
		dp.pop();	
		
		if(p->right) {
			st.push(p->right);
			dp.push(d+1);
		} else if(d > maxDepth) {
			maxDepth = d;
		}
		if(p->left) {
			st.push(p->left);
			dp.push(d+1);
		} else if(d > maxDepth) {
			maxDepth = d;
		}
	}
	
	return maxDepth;
}

TreeNode* createTree(int a[], int n) {
	if(n <= 0 ) {
		return NULL;
	}

	TreeNode **tree = new TreeNode*[n];	
	TreeNode *t = NULL;
	for(int i = 0 ; i < n; i++) {
		if(a[i] == 0) {
			tree[i] = NULL;
			continue;
		}
		t = new TreeNode(a[i]);
		tree[i] = t;
	}
	int j = 1;
	for(int i = 0; i < n && j < n; i++) {
		tree[i]->left = tree[j++];
		if(j < n) {
			tree[i]->right = tree[j++];
		}
	}

	return tree[0];
}

int main(int argc, char *argv[]) {
	int a[] = {1, 3, 2, 4, 0, 0, 0};
	TreeNode *t = createTree(a, sizeof(a)/sizeof(a[0]));
	cout << maxDepth(t) << endl;
	return 0;
}
