/*
	https://leetcode.com/problems/climbing-stairs/
	{
		You are climbing a stair case. It takes n steps to reach to the top.

		Each time you can either climb 1 or 2 steps. 
		In how many distinct ways can you climb to the top?
	}
*/

#include <iostream>

using namespace std;

int climbStairs(int n) {
	if(n <= 0) return 0;
	int ret = 0;
	int *t = new int[n+1];

	t[0] = 1;
	t[1] = 1;
	for(int i = 2; i <= n; i++) {
		t[i] = t[i-1] + t[i-2];
	}

	ret = t[n];
	delete[] t;
	t = NULL;

	return ret;
}

int main(int argc; char *argv[])
{
	cout << climbStairs(5) << endl;
	return 0;
}
