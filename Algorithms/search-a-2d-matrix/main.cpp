/*
https://leetcode.com/problems/search-a-2d-matrix/
{
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
}
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int n = matrix.size();
	if (n <= 0) {
		return false;
	}
	int m = matrix[0].size();
	/* quick sort */
	int i = 0, j = m*n-1;
	int t;
	while(i <= j) {
		t = (i+j)/2;
		int ii = t/m;
		int jj = t%m;
		if(matrix[ii][jj] < target) {
			i = t+1;
		} else if(matrix[ii][jj] > target) {
			j = t-1;
		} else {
			return true;
		}
	}

	return false;
}

vector<vector<int> > createVector(int a[][4], int n, int m) {
	vector<vector<int> > vv;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.clear();
		for(int j = 0; j < m; j++) {
			v.push_back(a[i][j]);
		}
		vv.push_back(v);
	}
	return vv;
}

int main(int argc, char *argv[]) {
	int A[][4] = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50},
	};
	vector<vector<int> > vv = createVector(A, 3, 4);
	cout << searchMatrix(vv, 11) << endl;	
	cout << searchMatrix(vv, 12) << endl;	
	return 0;
}
