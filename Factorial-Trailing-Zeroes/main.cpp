/*
	https://leetcode.com/problems/factorial-trailing-zeroes/
	{
		Given an integer n, return the number of trailing zeroes in n!.

		Note: Your solution should be in logarithmic time complexity.
	}
*/
#include <iostream>

using namespace std;

int trailingZeroes(int n) {
	int cnt = 0;
	while(n > 0) {
		int t = n / 5;
		cnt += t;
		n = t;	
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	cout << "0 => " << trailingZeroes(0) << endl;	
	cout << "100 => " << trailingZeroes(100) << endl;	
	return 0;
}
