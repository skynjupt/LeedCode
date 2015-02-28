#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		ret ^= A[i];
	}
	return ret;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 2, 3,1, 4};
	cout << singleNumber(a, sizeof(a)/sizeof(a[0])) << endl;;
	return 0;
}
