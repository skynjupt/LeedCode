/*
	https://leetcode.com/problems/maximum-product-subarray/
	{
		Find the contiguous subarray within an array (containing at least one number) which has the largest product.

		For example, given the array [2,3,-2,4],
		the contiguous subarray [2,3] has the largest product = 6.	
	}
*/
#include <iostream>

using namespace std;

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

int main(int argc, char *argv[])
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << maxProduct(a, sizeof(a)/sizeof(int)) << endl;	
	return 0;
}
