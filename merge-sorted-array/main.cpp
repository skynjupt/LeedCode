#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n) {
	int i, j, t;
	t = m+n-1;	
	for(i = m-1,j = n-1; i >= 0 && j >= 0; ) {
		if(A[i] > B[j]) {
			A[t--] = A[i--];
		} else {
			A[t--] = B[j--];
		}
	}	

	if(j >= 0) {
		while(j >= 0) {
			A[t--] = B[j--];
		}	
	}
}

void myPrint(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[100] = {1, 2, 3, 10, 15, 19};
	int b[] = {2, 3, 4, 5, 6};
	merge(a, 6, b, sizeof(b)/sizeof(b[0]));
	myPrint(a, 11);
	
	return 0;
}
