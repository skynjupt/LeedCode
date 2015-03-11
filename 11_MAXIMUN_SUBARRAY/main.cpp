/*
	https://leetcode.com/problems/maximum-subarray/
	{
		Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

		For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
		the contiguous subarray [4,-1,2,1] has the largest sum = 6.

		click to show more practice.

		More practice:
		If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.	
	}
*/

#include <iostream>

using namespace std;

int maxSubArray(int A[], int n) {
	if(n <= 0) return 0;	
	int *m = new int[n];
	int max = A[0];

	m[0] = A[0];		
	for(int i = 1; i < n; i++) {
		if(m[i-1] > 0) {
			m[i] = m[i-1] + A[i];
		} else {
			m[i] = A[i];
		}
		if(m[i] > max) {
			max = m[i];
		}
	}
	delete[] m;
	return max;
}

int main(int argc, char *argv[])
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(a, sizeof(a)/sizeof(int)) << endl;	
	return 0;
}
