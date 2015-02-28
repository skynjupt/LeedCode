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

int main(int argc, char *argv[])
{
	cout << "0=>" << climbStairs(0) << endl;
	cout << "1=>" << climbStairs(1) << endl;
	cout << "2=>" << climbStairs(2) << endl;
	cout << "3=>" << climbStairs(3) << endl;
	cout << "4=>" << climbStairs(4) << endl;
	cout << "5=>" << climbStairs(5) << endl;

	return 0;
}
