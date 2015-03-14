/*
https://leetcode.com/problems/reverse-bits/
{
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
}
*/
#include <iostream>

using namespace std;

#define uint32_t unsigned int

uint32_t reverseBits(uint32_t n) {
	int ret = 0;
	for(int i = 0; i<32; i++) {
		//ret = (ret<<1) + (n&1);
		ret = (ret<<1) | (n&1);
		n>>=1;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	uint32_t a = 43261596;
	cout << reverseBits(a) << endl;
	return 0;
}
