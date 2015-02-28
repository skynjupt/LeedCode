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

#if 0
int minDepth(TreeNode *root) {
	if(root == NULL) {
		return 0;
	}
	queue<TreeNode* > q;
	queue<int> c;
	TreeNode *t;
	q.push(root);
	c.push(1);
	int cnt;
	while(!q.empty()) {
		t = q.front();
		q.pop();	
		cnt = c.front();
		c.pop();
		if((t->left == NULL) && (t->right == NULL)) {
			return cnt;
		}
		if( t->left != NULL) {
			q.push(t->left);	
			c.push(cnt+1);
		}

		if( t->right != NULL) {
			q.push(t->right);
			c.push(cnt+1);
		}
	}
}
#endif


#if 0
int min_depth; 

void dfs(TreeNode *root, int cnt) {
	if(!root->left && !root->right) {
		if(cnt < min_depth) {
			min_depth = cnt;
			return;
		}
	}

	if(root->left) {
		dfs(root->left, cnt+1);
	}

	if(root->right) {
		dfs(root->right, cnt+1);
	}
	
}

int minDepth(TreeNode *root) {
	if(root == NULL) {
		return 0;
	}
	min_depth = INT_MAX; 
	dfs(root, 1);	
	return min_depth;
}
#endif

int dfs(TreeNode *root, int cnt) {
	if(!root->left && !root->right) {
		return cnt;
	}

	int min_left = INT_MAX;
	int min_right = INT_MAX;

	if(root->left) {
		min_left = dfs(root->left, cnt+1);
	}

	if(root->right) {
		min_right = dfs(root->right, cnt+1);
	}

	return min_left > min_right ? min_right	: min_left;
	
}

int minDepth(TreeNode *root) {
	if(root == NULL) {
		return 0;
	}
	return dfs(root, 1);	
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
	int a[] = {1,2,3,4,5,0,0};
	TreeNode * t = createTree(a, sizeof(a)/sizeof(a[0]));
	cout << minDepth(t) << endl;

	int b[] = {1,2,0};
	t = createTree(b, sizeof(b)/sizeof(b[0]));
	cout << minDepth(t) << endl;
	
	return 0;
}
