/*
	https://leetcode.com/problems/jump-game/
	{
		Given an array of non-negative integers, you are initially positioned at the first index of the array.

		Each element in the array represents your maximum jump length at that position.

		Determine if you are able to reach the last index.

		For example:
		A = [2,3,1,1,4], return true.

		A = [3,2,1,0,4], return false.
	}
*/
#include <iostream>

using namespace std;

bool canJump(int A[], int n) {
	int i = 0;
	while(i < n) {
		if(i + A[i] >= n-1) {
			return true;
		}

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

	return false;
}

int main(int argc, char *argv[]) {
	int A[] = {2,3,1,1,4};
	cout << canJump(A, sizeof(A)/sizeof(int)) << endl;
	int B[] = {3,2,1,0,4};
	cout << canJump(B, sizeof(B)/sizeof(int)) << endl;
	return 0;
}
