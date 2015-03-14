/*
https://leetcode.com/problems/subsets/
{
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:
}
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*
Input:	[4,1,0]
Output:	[[],[4],[1],[4,1],[0],[4,0],[1,0],[4,1,0]]
Expected:	[[],[0],[1],[4],[0,1],[0,4],[1,4],[0,1,4]]
*/

vector<vector<int> > subsets(vector<int> &S) {
	int n = S.size();
	int total = pow(2, n);
	vector<vector<int> > vv(total, vector<int>());	
	// sort
	sort(S.begin(), S.end());
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < total; j++) {
			if( ((j>>i) & 1) == 1 ) {
				vv[j].push_back(S[i]);
			}
		}
	}
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
	vector<int> s(3);
	s[0] = 4;
	s[1] = 1;
	s[2] = 0;
	vector<vector<int> > vv = subsets(s); 
	printVV(vv);
	return 0;
}
