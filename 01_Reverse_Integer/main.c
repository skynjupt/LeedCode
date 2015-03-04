/*
 * Reverse Interger
 * HarryWu
 * 2014-10-29 9:23 pm
 * url: https://oj.leetcode.com/problems/reverse-integer/
 *
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse_01(int x) {
	int ret = 0, n = 1, sign = 1;

	if(x < 0 ) 
	{
		x = -x;
		sign = -1;
	}
	while(x != 0)
	{

		ret = ret * 10 + x % 10;
		x = x / 10;	
	}
	return ret*sign;
}

int reverse(int x) {
	int ret = 0;

	while(x != 0)
	{
		if(ret > INT_MAX/10 || (ret == INT_MAX/10 && x%10 > 7) 
			|| ret < INT_MIN/10 || (ret == INT_MIN/10 && x%10 < -8)) {
			return 0;
		}
		ret = ret * 10 + x % 10;
		x = x / 10;	
	}
	return ret;
}

int main(int argc, char *argv[])
{
	printf("123 -> %d\n", reverse(123));
	printf("-123 -> %d\n", reverse(-123));
	printf("0 -> %d\n", reverse(0));
	printf("10 -> %d\n", reverse(10));
	printf("min -> %d\n", INT_MIN);
	printf("max -> %d\n", INT_MAX);
	printf("max+1 -> %d\n", INT_MAX+1);
	printf("max+2 -> %d\n", INT_MAX+2);
	printf("min-1 -> %d\n", INT_MIN-1);
	printf("min-2 -> %d\n", INT_MIN-2);
	printf("1000000003 -> %d\n", reverse(1000000003));
	printf("-2147447412 -> %d\n", reverse(-2147447412));
	printf("%d\n", -2147447412 == reverse(-2147447412));
	return 0;
}
