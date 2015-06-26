/*
	https://leetcode.com/problems/single-number/
	{
	Given an array of integers, every element appears twice except for one. 
	Find that single one.

	Note:
	Your algorithm should have a linear runtime complexity. 
	Could you implement it without using extra memory?
	}
*/

#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		ret ^= A[i];
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 2, 3,1, 4};
	cout << singleNumber(a, sizeof(a)/sizeof(a[0])) << endl;;
	return 0;
}
