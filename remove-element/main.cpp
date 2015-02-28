#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
	if(n < 1) {
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(A[i] != elem) {
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
	int a1[] = {3, 4, 2, 3, 4};
	int n = removeElement(a1, sizeof(a1)/sizeof(a1[0]), 5);
	printArray(a1, n);	
	return 0;
}
