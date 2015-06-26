/*
	https://leetcode.com/problems/n-queens-ii/
	{
		Follow up for N-Queens problem.

		Now, instead outputting board configurations, 
		return the total number of distinct solutions.
	}
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

void backtrack(int x, int solution[], bool mx[], bool md1[], bool md2[], int n, int &cnt) {
	// check 
	if(x == n) {
		cnt++;	
	}	

	for(int i = 0; i < n; i++) {
		int d1 = (x+i) % (2*n);
		int d2 = (x-i+2*n) % (2*n);	
		if((!mx[i]) && (!md1[d1]) && (!md2[d2])) {
			mx[i] = true;
			md1[d1] = true;
			md2[d2] = true;
			solution[x] = i;
			backtrack(x+1, solution, mx, md1, md2, n, cnt);
			mx[i] = false;	
			md1[d1] = false;
			md2[d2] = false;
		}
	}	
}

int totalNQueens(int n) {
	int solution[n];	
	bool mx[n]; 
	bool md1[2*n]; 
	bool md2[2*n]; 
	for(int i = 0; i < n; i++) {
		mx[i] = false;
	}
	for(int i = 0; i < 2*n; i++) {
		md1[i] = false;
		md2[i] = false;
	}
	int cnt = 0;	
	backtrack(0, solution, mx, md1, md2, n, cnt);
	return cnt;
}

int main(int argc, char *argv[]) {
	int cnt = totalNQueens(4);
	cout << cnt << endl;
	return 0;
}
