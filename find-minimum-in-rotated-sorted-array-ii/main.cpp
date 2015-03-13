/*
	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
	{
		Follow up for "Find Minimum in Rotated Sorted Array":
		What if duplicates are allowed?

		Would this affect the run-time complexity? How and why?
		Suppose a sorted array is rotated at some pivot unknown to you beforehand.

		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

		Find the minimum element.

		The array may contain duplicates.
	}
*/

#include <iostream>
#include <vector>
	
using namespace std;

int solve(vector<int> &num, int l, int r) {
	if(l >= r) return num[l];
	if(num[l] < num[r]) return num[l];
	int mid = (l+r)/2;
	if(num[mid] > num[r]) {
		solve(num, mid+1, r);
	} else if(num[mid] < num[r]) {
		solve(num, l, mid);
	} else {
		solve(num, l+1, r-1);
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
