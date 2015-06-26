/*
	https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	{
		Given a sorted array, remove the duplicates in place 
		such that each element appear only once and return the new length.

		Do not allocate extra space for another array, 
		you must do this in place with constant memory.

		For example,
		Given input array A = [1,1,2],

		Your function should return length = 2, and A is now [1,2].
	}
*/

#include <iostream>

using namespace std;

#if 0
int removeDuplicates(int A[], int n) {
	int N = 0;	
	for(int i = n-1; i >= 0; ) {
		int t = i-1;
		while( t >= 0 && A[i] == A[t]) {
			t--; 
		}	
		int j = t+1;
		int cnt = N;
		while(j < i && cnt > 0) {
			A[++j] = A[++i];
			cnt--;
		}
		N++;
		i = t;
	}  
	return N;
}
#endif

#if 0
int removeDuplicates(int A[], int n) {
	int N = 0;
	int i = 0;
	while(i < n) {
		int j = i+1;
		while(j < n && A[j] == A[i]) {
			j++;
		}
		if(j < n && j != N+1) {
			A[N+1] = A[j];	
		}
		i = j;
		N++;
	}
	return N;
}
#endif

int removeDuplicates(int A[], int n) {
	if(n < 2) {
		return n;
	}	
	
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(A[i] != A[i-1]) {
			A[cnt++] = A[i];		
		}
	}

	return cnt;
}
void printArray(int A[], int n) {
	for(int i = 0; i < n; i++) {
		cout << A[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a1[] = {3,3,3};
	int c = removeDuplicates(a1, sizeof(a1)/sizeof(a1[0]));
	printArray(a1, c);
	
	int a2[] = {3,3,3,4};
	c = removeDuplicates(a2, sizeof(a2)/sizeof(a2[0]));
	printArray(a2, c);

	int a3[] = {1,3,3,3,4};
	c = removeDuplicates(a3, sizeof(a3)/sizeof(a3[0]));
	printArray(a3, c);

	int a4[] = {1,3,3,3,4,4};
	c = removeDuplicates(a4, sizeof(a4)/sizeof(a4[0]));
	printArray(a4, c);

	int a5[] = {1,1,3,3,3,4,4};
	c = removeDuplicates(a5, sizeof(a5)/sizeof(a5[0]));
	printArray(a5, c);

	int a6[] = {1,2,3,4,5};
	c = removeDuplicates(a6, sizeof(a6)/sizeof(a6[0]));
	printArray(a6, c);

	int a7[] = {1,1,3,4};
	c = removeDuplicates(a7, sizeof(a7)/sizeof(a7[0]));
	printArray(a7, c);
	return 0;
}
