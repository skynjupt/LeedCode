#include <iostream>
#include <vector>
	
using namespace std;

#if 0
int solve(vector<int> &num, int l, int r) {
	if(l == r) return num[l];
	int mid = (l+r)/2;
	int left_min = 	solve(num, l, mid);	
	int right_min = solve(num, mid+1, r);
	if(left_min > right_min) {
		return right_min;
	} else {
		return left_min;
	}
}
#endif

int solve(vector<int> &num, int l, int r) {
	if(l == r) return num[l];
	if(num[l] < num[r]) return num[l];
	int mid = (l+r)/2;
	if(num[mid] > num[r]) {
		solve(num, mid+1, r);
	} else {
		solve(num, l, mid);
	}
}

int findMin(vector<int> &num) {
	return solve(num, 0, num.size()-1);
}

void creatVector(vector<int>& v, int a[], int n) {
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	} 
}

int main(int argc, char *argv[]) {
	vector<int> v;
	int a[] = {4, 5, 6, 7, 0, 1, 2};	
	creatVector(v, a, sizeof(a)/sizeof(a[0]));
	cout << findMin(v) << endl;
	vector<int> v1;
	int a1[] = {2, 1, 0, 7, 6, 5, 4};	
	creatVector(v1, a1, sizeof(a1)/sizeof(a1[0]));
	cout << findMin(v1) << endl;
	return 0;
}
