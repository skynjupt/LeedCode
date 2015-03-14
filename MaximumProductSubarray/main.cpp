/*
	https://leetcode.com/problems/maximum-product-subarray/
	{
		Find the contiguous subarray within an array (containing at least one number) 
		which has the largest product.

		For example, given the array [2,3,-2,4],
		the contiguous subarray [2,3] has the largest product = 6.
	}
*/

#include <iostream> 

using namespace std;

#define MIN(a, b) (((a)>(b))?(b):(a))
#define MAX(a, b) (((a)>(b))?(a):(b))

#if 0
/*
 * m[0] = -1
 * s[0] = 1
 * m[i] = MAX{ m[i-1] * A[i] , A[i] } , s[i] = s[i-1] * A[i]  {if A[i] >= 0}
 * m[i] = s[i-1] * A[i], s[i] = MIN{ m[i-1] * A[i], A[i] } {if A[i] < 0}
 * 
 * 
 *	
 */

int maxProduct(int A[], int n) {
	if(n <= 0) return 0;
	int *m = new int[n+1];
	int *s = new int[n+1];		

	int max = A[0];
	
	if(A[0] < 0) {
		m[0] = -1;
		s[0] = A[0];
	} else {
		m[0] = A[0];
		s[0] = 1;
	}
	for(int i = 1; i < n; i++) {
		if(A[i] < 0) {
			if(s[i-1] <= 0) {
				m[i] = s[i-1] * A[i];
			} else {
				m[i] = -1;  
			}
			
			if(m[i-1] >= 0) {
				s[i] = MIN(m[i-1]*A[i], A[i]);
			} else {
				s[i] = 1;
			}
		} else {
			if(m[i-1] >= 0) { 
				m[i] = MAX(m[i-1]*A[i], A[i]);
			} else {
				m[i] = MAX(-1, A[i]);
			}
			if(s[i-1] <= 0) {
				s[i] = s[i-1] * A[i];
			} else {
				s[i] = 1;
			}
		}
		if(m[i] >= 0 && m[i] > max) max = m[i];
		if(s[i] <= 0 && s[i] > max) max = s[i];
	}
	delete[] m;
	delete[] s;
	return max;
}
#else 

/*
	m[i] = MAX{m[i-1]*A[i], s[i-1]*A[i], A[i]}
	s[i] = MIN{m[i-1]*A[i], s[i-1]*A[i], A[i]}
 */

int maxProduct(int A[], int n) {
	if(n <= 0) return 0;
	int *m = new int[n+1];
	int *s = new int[n+1];		
	int max = A[0];

	m[0] = s[0] = A[0];
	int tmpMax = 0;
	int tmpMin = 0;
	for(int i = 1; i < n; i++) {
		if(A[i] > m[i-1] * A[i]) {
			tmpMax = A[i];
			tmpMin = m[i-1] * A[i];
		} else {
			tmpMax = m[i-1] * A[i];
			tmpMin = A[i];
		}
		
		if(s[i-1] * A[i] > tmpMax) tmpMax = s[i-1] * A[i]; 
		if(s[i-1] * A[i] < tmpMin) tmpMin = s[i-1] * A[i]; 

		m[i] = tmpMax;
		s[i] = tmpMin;
		
		if(m[i] > max) max = m[i];
	}	

	delete[] m;
	delete[] s;
	return max;
}
#endif

int main(int argc, char *argv[])
{
	int a[] = {-4, -3};
	cout << maxProduct(a, sizeof(a)/sizeof(int)) << endl;

	int b[] = {-3};
	cout << maxProduct(b, sizeof(b)/sizeof(int)) << endl;
	
	int c[] = {3};
	cout << maxProduct(c, sizeof(c)/sizeof(int)) << endl;
	
	int d[] = {0};
	cout << maxProduct(d, sizeof(d)/sizeof(int)) << endl;

	int e[] = {-3, 0, 4, -3, -5};
	cout << maxProduct(e, sizeof(e)/sizeof(int)) << endl;

	int f[] = {3, 0, -4};
	cout << maxProduct(f, sizeof(f)/sizeof(int)) << endl;

	int g[] = {3, 4};
	cout << maxProduct(g, sizeof(g)/sizeof(int)) << endl;

	int h[] = {2, -5, -2, -4, 3};
	cout << maxProduct(h, sizeof(h)/sizeof(int)) << endl;
	
	return 0;
}
