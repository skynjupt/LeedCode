#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

void backtrack(int x, int solution[], bool mx[], bool md1[], bool md2[], int n, vector<vector<string> > &vv) {
	// check 
	if(x == n) {
		vector<string> v;
		for(int i = 0; i < n; i++) {
			string s = "";
			for(int j = 0; j < n; j++) {
				if(solution[i] == j) {
					s += 'Q';
				} else {
					s += '.';
				}
			}
			v.push_back(s);
		}
		vv.push_back(v);
		return;
	}	

	for(int i = 0; i < n; i++) {
		int d1 = (x+i) % (2*n);
		int d2 = (x-i+2*n) % (2*n);	
		if((!mx[i]) && (!md1[d1]) && (!md2[d2])) {
			mx[i] = true;
			md1[d1] = true;
			md2[d2] = true;
			solution[x] = i;
			backtrack(x+1, solution, mx, md1, md2, n, vv);
			mx[i] = false;	
			md1[d1] = false;
			md2[d2] = false;
		}
	}	
}

vector<vector<string> > solveNQueens(int n) {
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
	vector<vector<string> > vv;
	backtrack(0, solution, mx, md1, md2, n, vv);
	return vv;
}

void printVV(vector<vector<string> > &vv) {
	int n = vv.size();
	for(int i = 0; i < n; i++) {
		cout << "solution: " << i << endl;
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << endl;
		}
	}
}

int main(int argc, char *argv[]) {
	vector<vector<string> > vv = solveNQueens(12);
	printVV(vv);
	return 0;
}
