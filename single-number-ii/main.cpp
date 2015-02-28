#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
	int ones = 0;
	int twos = 0;
	for(int i = 0; i < n; i++) {
		ones = (ones ^ A[i]) & ~twos;
		twos = (twos ^ A[i]) & ~ones;
	}
	return ones;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4, 3, 4, 3, 1, 4, 1};
	cout << singleNumber(a, sizeof(a)/sizeof(a[0])) << endl;
	return 0;
}
