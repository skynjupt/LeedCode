#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > vv;
	vector<int> v(3,0);
	int n = num.size();
	if(n <= 2) {
		return vv;
	}

	sort(num.begin(), num.end());
	for(int i = 0; i < n-2; i++) {
		int j = i+1;
		int k = n-1;
		while(j < k) {
			int sum = num[i] + num[j] + num[k];	
			if(sum == 0) {
				v[0] = num[i];
				v[1] = num[j];
				v[2] = num[k];
				vv.push_back(v);
				
				while(j+1 < k && num[j+1] == num[j]) {
					j++;
				}
				while(j < k-1 && num[k-1] == num[k]) {
					k--;
				}
			}
			sum > 0 ? k-- : j++;
		}
		while(i+1 < n-2 && num[i+1] == num[i]) {
			i++;
		}
	}
	return vv;
}

vector<int> createVector(int a[], int n) {
	vector<int> v;
	for(int ai = 0; ai < n; ai++) {
		v.push_back(a[ai]);	
	}
	return v;
}

void printVector(vector<vector<int> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ",";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	int a[] = {-1,0,1,2,-1,-4,-1.-1,-2,-3,-4,-3,0,0,3};
	vector<int> v = createVector(a, sizeof(a)/sizeof(int));
	vector<vector<int> > vv = threeSum(v);
	printVector(vv);	
	return 0;
}
