/*
 * https://oj.leetcode.com/problems/unique-binary-search-trees/
 */
#include <iostream>

using namespace std;
/*
//Wrong Answer: A[i] = 2A[i-1] + A[i-2] + ... A[0] when A[0] = 1 
int numTrees(int n) {
	int A[n], sum = 0;
	A[0] = 1;
	sum = A[0];
	for(int i = 1; i < n; i++) {
		A[i] = sum + A[i-1];	
		sum = sum + A[i];
	}

	return A[n-1];	
}
*/

// Right Ansser: A[i] = A[i-1]*A[0] + A[i-2]*A[1] + A[i-k]*A[k-1] // i>=k>=1 && A[0] = 1
int numTrees(int n) {
	if(n <= 0) return 0;

	int A[n+1];
	A[0] = 1;
	for(int i = 1; i <= n; i++) {
		A[i] = 0;	
		for(int k = 1; k <= i; k++) {
			A[i] += A[k-1]*A[i-k];
		}
	}

	return A[n];	
}

int main(int argc, char *argv[])
{
	cout << "1 -> " << numTrees(1) << endl;
	cout << "2 -> " << numTrees(2) << endl;
	cout << "3 -> " << numTrees(3) << endl;
	/*
		Input:	4
		Output:	13
		Expected:	14
	 */
	cout << "4 -> " << numTrees(4) << endl;
	return 0;
}
