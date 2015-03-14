/*
https://leetcode.com/problems/number-of-1-bits/
{
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
}
*/
#include <iostream>

using namespace std;

#define uint32_t unsigned int 

#if 0
int hammingWeight(uint32_t n) {
	int cnt = 0;
	for(int i = 0; i < 32; i++) {
		if(n&1 == 1) {
			cnt++;	
		}	
		n >>= 1;
	}

	return cnt;
}
#endif


int hammingWeight(uint32_t n) {
	int cnt = 0;
	while(n) {
		cnt++;
		n &= (n-1); // remove one '1' from n
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	uint32_t a = 11;
	cout << hammingWeight(a) << endl;
	return 0;
}
