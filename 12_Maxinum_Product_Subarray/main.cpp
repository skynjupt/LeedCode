#include <iostream>

using namespace std;

int maxSubArray(int A[], int n) {
	if(n <= 0) return 0;	
	int *m = new int[n];
	int *s = new int[n]
	int max = A[0];

	s[0] = A[0];
	m[0] = A[0]
	for(int i = 1; i < n; i++) {
		if(A[i] > 0) {
			m[i] = m[i-1]*A[i];
		} else {
			m[i] = A[i];
		}
		if(m[i] > max) {
			max = m[i];
		}
	}
	delete[] m;
	delete[] s;
	return max;
}

int main(int argc, char *argv[])
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxSubArray(a, sizeof(a)/sizeof(int)) << endl;	
	return 0;
}
