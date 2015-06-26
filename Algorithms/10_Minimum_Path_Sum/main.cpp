/*
	https://leetcode.com/problems/minimum-path-sum/
	{
		Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

		Note: You can only move either down or right at any point in time.
	}
*/


#include <iostream>
#include <vector>

using namespace std;

/*
	M[0][0] = A[0][0]
	M[i][j] = min{ M[i-1][j], M[i][j-1] } + A[i][j]
		1 < i < m && 1 < j < n

 */

#define MIN(a, b) (((a)<(b))?(a):(b))

int minPathSum(vector<vector<int> > &grid) {
	if(grid.empty() || grid[0].empty())
		return 0;
	int m = grid.size();
	int n = grid[0].size();

	int vv[m][n];
	
	vv[0][0] = grid[0][0];
	for(int i = 1; i < m; i++) {
		vv[i][0] = vv[i-1][0] + grid[i][0];	
	}
	
	for(int i = 1; i < n; i++) {
		vv[0][i] = vv[0][i-1] + grid[0][i];	
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			vv[i][j] = MIN(vv[i-1][j], vv[i][j-1]) + grid[i][j];	
		}
	}

	return vv[m-1][n-1];	
}

int main(int argc, char *argv[])
{
/*
	vector<vector<int> > vv = { 
			{1, 2, 3}, 
			{2, 3, 1},
			{3, 2, 1}};
*/
	vector<int> v;
	vector<vector<int> > vv; 
/*
	int a[3][3] ={  {1, 2, 3}, 
			{2, 3, 1},
			{3, 2, 1}};
	#define N 3
	#define M 3

	int a[2][2] ={  {2, 3}, 
			{2, 1}};
	#define N 2
	#define M 2
*/
	int a[1][1] ={{1}}; 
		
	#define N 1
	#define M 1

	vv.clear();
	for(int i = 0; i < N; i++)
	{
		v.clear();
		for(int j = 0; j < M; j++) {
			v.push_back(a[i][j]);
		}
		vv.push_back(v);
	}

	cout << minPathSum(vv) << endl;
	return 0;
}
