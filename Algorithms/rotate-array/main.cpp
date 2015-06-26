/*
https://leetcode.com/problems/rotate-array/
{
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
}
*/
#include <iostream>

using namespace std;

void rotate(int nums[], int n, int k) {
	if( n == 0 || k%n == 0 ) {
		return;
	}

	int copyNums[n];
	for(int i = 0; i < n; i++) {
		copyNums[i] = nums[i];
	}

	for(int i = 0; i < n; i++) {
		nums[(k+i)%n] = copyNums[i];
	}
}

void myPrint(int nums[], int n) {
	for(int i = 0; i < n; i++) {
		cout << nums[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1,2,3,4,5,6,7};
	rotate(a, sizeof(a)/sizeof(a[0]), 3);
	myPrint(a, sizeof(a)/sizeof(a[0]));

	return 0;
}
