/*
	https://leetcode.com/problems/jump-game-ii/
	{
		Given an array of non-negative integers, you are initially positioned at the first index of the array.

		Each element in the array represents your maximum jump length at that position.

		Your goal is to reach the last index in the minimum number of jumps.

		For example:
		Given array A = [2,3,1,1,4]

		The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
	}
*/

#include <iostream>

using namespace std;

int jump(int A[], int n) {
	if(n <= 1) return 0;
	int i = 0;
	int ans = 0;
	while(i < n) {
		if(i + A[i] >= n-1) {
			return ++ans;
		}
		ans++;

		if(A[i] == 0) {
			break;
		}

		int maxStep = -1;
		int maxIndex = -1;
		for(int j = i+1; j <= i+A[i] && j < n; j++) {
			if(A[j]+j > maxStep) {
				maxStep = A[j]+j;
				maxIndex = j;	
			}	
		}

		if(maxStep != -1) {
			i = maxIndex;
		}
	}

	return -1;
}

int main(int argc, char *argv[]) {
	int A[] = {2,3,1,1,4};
	cout << jump(A, sizeof(A)/sizeof(int)) << endl;
	int B[] = {3,2,1,0,4};
	cout << jump(B, sizeof(B)/sizeof(int)) << endl;
	return 0;
}
