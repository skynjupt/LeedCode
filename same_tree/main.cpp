#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> convertTree(TreeNode *root) {
	vector<int> v;
	TreeNode *t;
	stack<TreeNode *> st;

	st.push(root);
	while(!st.empty()) {
		t = st.top();
		st.pop();
		if(t == NULL) {
			v.push_back(0);
			continue;
		}
		v.push_back(t->val);
		st.push(t->right);		
		st.push(t->left);
	}

	return v;
}

bool isSameTree(TreeNode *p, TreeNode *q) {
	vector<int> vp = convertTree(p);
	vector<int> vq = convertTree(q);

	int n = vp.size();
	int m = vq.size();	

	if(n == m) {
		int i;
		for(i = 0; i < n; i++) {
			if(vp[i] != vq[i]) {
				break;
			}
		}	

		if(i == n) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
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
	int a[] = {1, 3, 2, 4, 0, 0, 5};
	TreeNode *t1 = createTree(a, sizeof(a)/sizeof(a[0]));
	int b[] = {1, 3, 2, 4, 0, 5, 0};
	TreeNode *t2 = createTree(b, sizeof(b)/sizeof(b[0]));
	cout << isSameTree(t1, t1) << endl;
	cout << isSameTree(t1, t2) << endl;
	return 0;
}
