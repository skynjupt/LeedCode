/*
	https://leetcode.com/problems/range-sum-query-immutable/
	{
		Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

		Example:
		Given nums = [-2, 0, 3, -5, 2, -1]

		sumRange(0, 2) -> 1
		sumRange(2, 5) -> -1
		sumRange(0, 5) -> -3
		Note:
		You may assume that the array does not change.
		There are many calls to sumRange function.
	}
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> gnums;

void makeNumArray(vector<int> &nums) {
	if(nums.size() > 0 ) {
		gnums.push_back(nums[0]);

		for(int i = 1; i < nums.size(); i++) {
			gnums.push_back(gnums[i-1]+nums[i]);
		}	
	}
}

int sumRange(int i, int j) {
	if(i == 0) return gnums[j];
	return gnums[j] - gnums[i-1];
}

vector<int> makeVector(int a[], int n) {
	vector<int> ret;
	for(int i = 0; i < n; i++) {
		ret.push_back(a[i]);
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int a[] = {-2, 0, 3, -5, 2, -1};
	vector<int> nums = makeVector(a, sizeof(a)/sizeof(a[0]));
	makeNumArray(nums);
	cout << "sumRange(0, 2) = " << sumRange(0, 2) << endl;
	cout << "sumRange(2, 5) = " << sumRange(2, 5) << endl;
	cout << "sumRange(0, 5) = " << sumRange(0, 5) << endl;
	return 0;
}
