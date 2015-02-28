#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;	
}

void backTracking(int x, int n, vector<int> &v, vector<vector<int> > &vv) {
	if(x == n) {
		vv.push_back(v);	
		return;
	}

	for(int i = x; i < n; i++) {
		swap(v[x], v[i]);
		backTracking(x+1, n, v, vv);
		swap(v[x], v[i]);	
	}
}

vector<vector<int> > permute(vector<int> &num) {
	int n = num.size();
	vector<vector<int> > vv;
	backTracking(0, n, num, vv);	
	return vv;
}

vector<int> createVector(int a[], int n) {
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);	
	}
	return v;
}

void printVector(vector<vector<int> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ", ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int a[] = {3, 2, 1, 5};
	vector<int> v = createVector(a, sizeof(a)/sizeof(a[0]));
	vector<vector<int> > vv = permute(v);
	printVector(vv);	
	return 0;
}
