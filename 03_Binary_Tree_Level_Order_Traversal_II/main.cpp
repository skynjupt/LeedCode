#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom1(TreeNode *root);
vector<vector<int> > levelOrderBottom2(TreeNode *root);

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	int ret = random()%2; 
	if (ret == 0) {
		cout << "levelOrderBottom1:" << endl;
		return levelOrderBottom1(root);
	} else if(ret == 1) {
		cout << "levelOrderBottom2:" << endl;
		return levelOrderBottom2(root);
	}
}

vector<vector<int> > levelOrderBottom1(TreeNode *root) {
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
#if 0
	vector< vector<int> > vv_ret;

	for(int i = vv.size()-1; i >= 0; i--) {
		vv_ret.push_back(vv[i]);
	}

	return vv_ret;
#else 
	reverse(vv.begin(), vv.end());
	return vv;
#endif
}

vector<vector<int> > levelOrderBottom2(TreeNode *root) {
	vector<vector<int> > vv;
	vector<int> v;
	
	
	vector<vector<int> > vv_left;
	vector<vector<int> > vv_right;

	if(root && root->left) {
		vv_left = levelOrderBottom2(root->left);
	}
	if(root && root->right) {
		vv_right = levelOrderBottom2(root->right);
	}

	// merge
#if 0
// wrong answer 1
	for(int i = 0; i < vv_left.size() || i < vv_right.size(); i++) {
		if(i < vv_left.size() && i < vv_right.size()) {
			vv_left[i].insert(vv_left[i].end(), vv_right[i].begin(), vv_right[i].end());
			vv.push_back(vv_left[i]);
		} else if(i < vv_left.size()) {
			vv.push_back(vv_left[i]);
		} else if(i < vv_right.size()) {
			vv.push_back(vv_right[i]);
		}	
	}	
// wrong answer 2
	int i, j;
	for(i = vv_left.size()-1, j = vv_right.size()-1; i >= 0 || j >= 0; ) {
		if(i >= 0 && j >= 0) {
			vv_left[i].insert(vv_left[i].end(), vv_right[j].begin(), vv_right[j].end());
			vv.push_back(vv_left[i]);
			i--;
			j--;
		} else if(i >= 0) {
			vv.push_back(vv_left[i]);
			i--;
		} else if(j >= 0) {
			vv.push_back(vv_right[j]);
			j--;
		}	
	}	
#else 
	int left_size = vv_left.size();
	int right_size = vv_right.size();
	int i,j;	
	for(i = 0, j = 0; i < vv_left.size() || j < vv_right.size(); ) {
		if((left_size > right_size) && (i < left_size - right_size)) {
			vv.push_back(vv_left[i]);
			i++;
		} else if((left_size < right_size) && (j < right_size - left_size)) {
			vv.push_back(vv_right[j]);
			j++;
		} else if(i < vv_left.size() && j < vv_right.size()) {
			vv_left[i].insert(vv_left[i].end(), vv_right[j].begin(), vv_right[j].end());
			vv.push_back(vv_left[i]);
			i++;
			j++;
		} 
#if 0
		else if(i < vv_left.size()) {
			vv.push_back(vv_left[i]);
			i++;
		} else if(j < vv_right.size()) {
			vv.push_back(vv_right[j]);
			j++;
		}	
#endif
	}	

#endif
	if(root) {
		v.push_back(root->val);
		vv.push_back(v);	
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
#if 0
	TreeNode* ret = tree[0];
	delete []tree;
	return ret;
#else 
	return tree[0];
#endif
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
//		delete n;
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
	vv = levelOrderBottom(p);
	printMatrix(vv);
	
	int a[] = {3, 9, 20, 0, 0, 15, 7};
	p = createTree(a, sizeof(a)/sizeof(a[0]));	
	printTree_level_order(p);
	vv = levelOrderBottom(p);
	printMatrix(vv);

	int b[] = {1, 2, 3, 4, 5, 0, 0};
	p = createTree(b, sizeof(b)/sizeof(b[0]));	
	printTree_level_order(p);
	vv = levelOrderBottom(p);
	printMatrix(vv);
	
	int c[] = {1, 0, 2, 3};
	p = createTree(c, sizeof(c)/sizeof(c[0]));	
	printTree_level_order(p);
	vv = levelOrderBottom(p);
	printMatrix(vv);

	int d[] = {1, 2, 0, 3, 0, 4, 0, 5};
	p = createTree(d, sizeof(d)/sizeof(d[0]));	
	printTree_level_order(p);
	vv = levelOrderBottom(p);
	printMatrix(vv);

	int e[] = {1, 2, 3, 4, 0, 0, 5};
	p = createTree(e, sizeof(e)/sizeof(e[0]));	
	printTree_level_order(p);
	vv = levelOrderBottom(p);
	printMatrix(vv);
	return 0;
}
