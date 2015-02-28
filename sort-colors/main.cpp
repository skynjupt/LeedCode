#include <iostream>

using namespace std;
#if 0
void qsort(int A[], int left, int right) {
	if(left < right) {
		int l = left, r = right;
		int t = A[l];
		while(l < r) {
			while(l < r && A[r] >= t) r--;
			A[l] = A[r];
			while(l < r && A[l] <= t) l++;
			A[r] = A[l];
		}
		A[l] = t;
		qsort(A, left, l-1);
		qsort(A, l+1, right);
	}
}

void sortColors(int A[], int n) {
	qsort(A, 0, n-1);	
}
#endif

#if 0
void sortColors(int A[], int n) {
	int reds = -1; // the sum of red
	int whites = -1; // the sum of red and white
	int blues = -1; // the sum of red、white and blue

	for(int i = 0; i < n; i++) {
		if(A[i] == 0) {
			A[++blues] = 2;
			A[++whites] = 1;
			A[++reds] = 0;
		} else if(A[i] == 1) {
			A[++blues] = 2;
			A[++whites] = 1;
		} else if(A[i] == 2) {
			A[++blues] = 2;
		}
	}
}
#endif

void sortColors(int A[], int n) {
	int blues = n-1; 
	int reds = 0;
	for(int i = 0; i <= blues ; i++) {
		while(A[i] == 2 && i < blues) {
			swap(A[i], A[blues--]);
		}

		while(A[i] == 0 && i > reds) {
			swap(A[i], A[reds++]);
		}
	}
}
void print(int A[], int n) {
	for(int i = 0; i < n; i++) {
		cout << A[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int A[] = {0,2,1,0,2,0,2,1,2,0,2,0,2,1,1,2,0};
	sortColors(A, sizeof(A)/sizeof(A[0]));	
	print(A, sizeof(A)/sizeof(A[0]));

	int B[] = { 2,2,1,2,1,1,1,0,0,2,1,0,2,1,2,2,1,1,1,1,1,0,2,0,2,0,2,2,1,0,2,1,0,2
		,1,2,0,0,0,0,2,1,1,2,0,1,2,2,0,0,2,2,0,1,0,1,0,0,1,1,1,0,0,2,2,2,1,0,0
		,2,1,0,1,0,2,2,1,2,1,1,2,1,1,0,0,2,1,0,0 };
	sortColors(B, sizeof(B)/sizeof(B[0]));	
	print(B, sizeof(B)/sizeof(B[0]));
	return 0;
}
