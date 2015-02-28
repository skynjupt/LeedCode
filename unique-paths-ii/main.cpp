#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {

	if (m <=0 || n <= 0) return 0;

	int a[m][n];  
	for(int i = 0; i < m; i++) {
		a[i][0] = 1;
	}
	for(int i = 0; i < n; i++) {
		a[0][i] = 1;
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			a[i][j] = a[i-1][j]+a[i][j-1];
		}
	}
	return a[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int dp[m][n];
	if(obstacleGrid[0][0] == 1) {
		dp[0][0] = 0;
	} else {
		dp[0][0] = 1;
	}
	for(int i = 1; i < m; i++) {
		if(obstacleGrid[i][0] == 1) {
			dp[i][0] = 0;
		} else {
			dp[i][0] = dp[i-1][0];
		}
	}
	for(int i = 1; i < n; i++) {
		if(obstacleGrid[0][i] == 1) {
			dp[0][i] = 0;
		} else {
			dp[0][i] = dp[0][i-1];
		}
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(obstacleGrid[i][j] == 1) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}

	return dp[m-1][n-1];
}

vector<vector<int> > createObstacleGrid(int a[][3], int n) {
	vector<vector<int> > vv;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.clear();
		for(int j = 0; j < 3; j++) {
			v.push_back(a[i][j]);	
		}
		vv.push_back(v);
	}
	return vv;
}

int main(int argc, char *argv[])
{
#if 0
	cout << "0,1 = " << uniquePaths(0,1) << endl;
	cout << "1,2 = " << uniquePaths(1,2) << endl;
	cout << "3,2 = " << uniquePaths(3,2) << endl;
	cout << "2,2 = " << uniquePaths(2,2) << endl;
#endif
	int a[][3] = {
		{0,0,0},
		{0,1,0},
		{0,0,0},
	};
	vector<vector<int> > vv;
	vv = createObstacleGrid(a, 3);
	cout << uniquePathsWithObstacles(vv) << endl;
	return 0;
}
