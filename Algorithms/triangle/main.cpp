/*
https://leetcode.com/problems/triangle/
{
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	int dp[n];
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < triangle[i].size(); j++) {
			if(i == n-1) {
				dp[j] = triangle[i][j];
			} else {
				dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);			
			}
		}
	}
	return dp[0];
}

vector<vector<int> > createTriangle(int a[], int n) {
	vector<vector<int> > vv;
	vector<int> v;
	int step = 0;
	for(int i = 0; i < n; i+=step) {
		step++;
		v.clear();
		for(int j = 0; j < step; j++) {
			v.push_back(a[i+j]);	
		}
		vv.push_back(v);
	}
	return vv;
}

int main(int argc, char *argv[]) {
#if 1
	int a[] = {2,3,4,6,5,7,4,1,8,3};
	vector<vector<int> > triangle = createTriangle(a, sizeof(a)/sizeof(a[0]));
	cout << minimumTotal(triangle) << endl;
#endif
#if 0
	int a[] = {-1, 2, 3, 1, -1, -1};
	vector<vector<int> > triangle = createTriangle(a, sizeof(a)/sizeof(a[0]));
	cout << minimumTotal(triangle) << endl;
#endif
	return 0;
}
