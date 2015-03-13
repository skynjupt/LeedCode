/*
	https://leetcode.com/problems/combinations/
	{
		Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

		For example,
		If n = 4 and k = 2, a solution is:

		[
		  [2,4],
		  [3,4],
		  [2,3],
		  [1,2],
		  [1,3],
		  [1,4],
		]
	}
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vv;

void backTracking(int a[], int m, int s, int n, int k) {
	if(m == k) {
		vector<int> v;
		for(int i = 0; i < k; i++) {
			v.push_back(a[i]);
		}
		vv.push_back(v);
		return;
	}	

	for(int i = s; i <= n; i++) {
		if(n-i+1+m < k) {
			return;
		}
		a[m] = i;		
		backTracking(a, m+1, i+1, n, k);
	}
}

vector<vector<int> > combine(int n, int k) {
	if(k > n || n <= 0) {
		return vv;
	}	
	int A[k];
	backTracking(A, 0, 1, n, k);	
	return vv;
}

void printVV(vector<vector<int> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ", ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	vector<vector<int> > tt = combine(4, 3);
	printVV(tt);
	return 0;
}
