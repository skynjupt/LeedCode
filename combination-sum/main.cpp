#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > vv;

void backTracking(vector<int> &v, int n, vector<int> &candidates, int m, int target) {
	int total = candidates.size();
	if(target == 0) {
		vector<int> vt;
		for(int i = 0; i < n; i++) {
			vt.push_back(v[i]);
		}
		vv.push_back(vt);
		return;
	}

	for(int i = m; i < total; i++) {
		int t = target - candidates[i];
		if(t >=0) {
			if(v.empty() || v.size() <= n) {
				v.push_back(candidates[i]);
			} else {
				v[n] = candidates[i];
			}
			n++;
			backTracking(v, n, candidates, i, t);
			n--;
		} else {
			break;
		}	
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	vector<int> v;
	sort(candidates.begin(), candidates.end());
	backTracking(v, 0, candidates, 0, target);
	return vv;
}

vector<int> createV(int a[], int n) {
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);	
	}
	return v;
}

void printVV(vector<vector<int> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ",";
		}
		cout << endl;
	}	
}



int main(int argc, char *argv[]) {
	int a[] = {2, 3, 6, 7};	
	vector<int> v = createV(a, sizeof(a)/sizeof(a[0]));
	vector<vector<int> > tt = combinationSum(v, 7);
	printVV(tt);
	return 0;
}
