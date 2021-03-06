/*
	https://leetcode.com/problems/unique-paths/
	{
		A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

		The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

		How many possible unique paths are there?	
	}
*/


#include <iostream>

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

int main(int argc, char *argv[])
{
	cout << "0,1 = " << uniquePaths(0,1) << endl;
	cout << "1,2 = " << uniquePaths(1,2) << endl;
	cout << "3,2 = " << uniquePaths(3,2) << endl;
	cout << "2,2 = " << uniquePaths(2,2) << endl;
	return 0;
}
