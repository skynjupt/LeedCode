/*
https://leetcode.com/problems/symmetric-tree/
{
Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
}
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#if 0
bool solve(TreeNode *p, TreeNode *q) {
	if(p->val != q->val) {
		return false;
	}

	bool flag1 = false;
	bool flag2 = false;

	if(p->left && q->right) {
		flag1 = solve(p->left, q->right);
	} else if(p->left || q->right) {
		flag1 = false;
	} else {
		flag1 = true;	
	}

	if(p->right && q->left) {
		flag2 = solve(p->right, q->left);
	} else if(p->right || q->left) {
		flag2 = false;
	} else {
		flag2 = true;
	}

	if(flag1 && flag2) {
		return true;
	} else {
		return false;
	}
}

bool isSymmetric(TreeNode *root) {
	if(root == NULL) {
		return true;
	}	

	if(root->left && root->right) {
		return solve(root->left, root->right);
	} else if(root->left || root->right) {
		return false;
	} else {
		return true;
	}
}
#endif

bool isSymmetric(TreeNode *root) {
	if(root == NULL) {
		return true;
	}	

	queue<TreeNode *> q1, q2;
	if(root->left && root->right) {
		q1.push(root->left);
		q2.push(root->right);
		TreeNode *t1, *t2;
		while((!q1.empty()) && (!q2.empty())) {
			t1 = q1.front();
			q1.pop();
			t2 = q2.front();
			q2.pop();
			if(t1->val != t2->val) {
				return false;
			}

			if(t1->left && t2->right) {
				q1.push(t1->left);
				q2.push(t2->right);	
			} else if(t1->left || t2->right) {
				return false;	
			}

			if(t1->right && t2->left) {
				q1.push(t1->right);
				q2.push(t2->left);	
			} else if(t1->right || t2->left) {
				return false;	
			}
		} 	

		if((!q1.empty()) || (!q2.empty())) {
			return false;
		} else {
			return true;
		}
		
	} else if(root->left || root->right) {
		return false;
	} else {
		return true;
	}
}

TreeNode* createTree(int a[], int n) {
	TreeNode *trees[n];
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			trees[i] = NULL;
			continue;
		}
		trees[i] = new TreeNode(a[i]);
	}


	int j = 1;
	for(int i = 0; i < n && j < n; i++) {
		if(trees[i]) {
			trees[i]->left = trees[j++];
			if(j < n) {
				trees[i]->right = trees[j++];	
			} 
		}
	}

	return trees[0];
}

int main(int argc, char *argv[]) {
	int a1[] = {1,2,2,3,4,4,3};
	TreeNode *t = createTree(a1, sizeof(a1)/sizeof(a1[0]));
	cout << isSymmetric(t) << endl;

	int a2[] = {1,2,2,0,3,0,3};
	t = createTree(a2, sizeof(a2)/sizeof(a2[0]));
	cout << isSymmetric(t) << endl;

	int a3[] = {1,2,2,0,3,3,0};
	t = createTree(a3, sizeof(a3)/sizeof(a3[0]));
	cout << isSymmetric(t) << endl;

	int a4[] = {1,2,2,3,0,0,3};
	t = createTree(a4, sizeof(a4)/sizeof(a4[0]));
	cout << isSymmetric(t) << endl;
	return 0;
}
