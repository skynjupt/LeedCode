/*
	https://leetcode.com/problems/binary-search-tree-iterator/
	{
		Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

		Calling next() will return the next smallest number in the BST.

		Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
	}
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}	
};

class BSTIterator {
private:
	stack<TreeNode* > st;	

	void pushLeft(TreeNode *root) {
		TreeNode *p = root;
		while(p != NULL) {
			st.push(p);
			p = p->left;
		}
	}
	
public:
	BSTIterator(TreeNode *root) {
		pushLeft(root);
	}

	bool hasNext() {
		return !st.empty();
	}

	int next() {
		TreeNode *p = st.top();
		st.pop();
		pushLeft(p->right);	
		return p->val;
	}
};

TreeNode* createBST(int a[], int n) {
	vector<TreeNode* > vt;		
	TreeNode *t;

	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			vt.push_back(NULL);
			continue;
		}
		t = new TreeNode(a[i]);
		vt.push_back(t);
	}

	int j = 1;	
	int i = 0; 
	for(int i = 0; i < n && j < n; i++) {
		if(vt[i] == NULL) {
			continue;
		}	
		
		vt[i]->left = vt[j++];
		if(j < n) {
			vt[i]->right = vt[j++];
		}
	}
	return vt[0];
}

int main(int argc, char *argv[]) {
	int a[] = {7, 3, 9, 2, 4, 8, 0};
	TreeNode *t = createBST(a, sizeof(a)/sizeof(a[0]));
	BSTIterator it = BSTIterator(t);
	while(it.hasNext()) {
		cout << it.next() << ", ";
	}	
	cout << endl;
	return 0;
}

