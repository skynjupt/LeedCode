#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
	if(n <= 0) {
		return 0;
	}

	int s = 0;
	int d = 0;
	for(int i = 1; i < n; i++) {
		if(A[i] == A[s]) {
			if(d == 0) {
				A[++s] = A[i];
				d++;
			}
		} else {
			A[++s] = A[i];
			d = 0;	
		}	
	}
	return s+1;
}

int main(int argc, char *argv[]) {
	int A[] = {1, 1, 1, 2, 2, 3};
	int n = removeDuplicates(A, sizeof(A)/sizeof(A[0]));
	for(int i = 0; i < n; i++) {
		cout << A[i] << ", " ;
	}
	cout << endl;


	return 0;
}
