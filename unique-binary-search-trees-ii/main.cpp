#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dumpTree(TreeNode *root, int offset) {
	if(!root) {
		return NULL;
	}
	TreeNode *t = new TreeNode(root->val+offset);
	t->left = dumpTree(root->left, offset);
	t->right = dumpTree(root->right, offset);
	return t;
}

vector<TreeNode *> generateTrees(int n) {
	vector<vector<TreeNode *> > dp;
	vector<TreeNode *> v;
	v.push_back(NULL);
	dp.push_back(v);	

	for(int l = 1; l <= n; l++) {
		v.clear();
		for(int i = 0; i < l; i++) {
			for(auto left:dp[i]) {
				for(auto right:dp[l-i-1]) {
					TreeNode *root = new TreeNode(i+1);
					root->left = left;
					root->right = dumpTree(right,i+1);	
					v.push_back(root);
				}
			}	
		}
		dp.push_back(v);
	}		
	return dp[n];
}

void bfs(TreeNode *root) {
	if(root == NULL) {
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode *t = q.front();
		q.pop();
		if(t == NULL) {
			cout << "#,";
			continue;
		}
		cout << t->val << ",";
		q.push(t->left);
		q.push(t->right);
	}

	cout << endl;
}

void printTrees(vector<TreeNode *> trees) {
	for(int i = 0; i < trees.size(); i++) {
		bfs(trees[i]);			
	}	
}

int main(int argc, char *argv[]) {
	vector<TreeNode *> v = generateTrees(3);
	printTrees(v);	
	return 0;
}
