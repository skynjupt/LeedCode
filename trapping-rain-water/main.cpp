#include <iostream>

using namespace std;

int trap(int A[], int n) {
	int low = 0;
	int high = n-1;	
	int leftMax = 0;
	int rightMax = 0;
	int ans = 0;
	
	while(low <= high) {
		leftMax = max(A[low], leftMax);
		rightMax = max(A[high], rightMax);	
		if(leftMax < rightMax) {
			ans += leftMax-A[low];
			low++;
		} else {
			ans += rightMax-A[high];
			high--;
		}	
	}
	
	return ans;
}

int main(int argc, char *argv[]) {
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << trap(a, sizeof(a)/sizeof(int)) << endl;	
	return 0;
}
