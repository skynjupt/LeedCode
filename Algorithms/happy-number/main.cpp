/*
	https://leetcode.com/problems/happy-number/
	{
		Write an algorithm to determine if a number is "happy".
		A happy number is a number defined by the following process: Starting with any positive integer, 
		replace the number by the sum of the squares of its digits, and repeat the process until the number 
		equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
		Those numbers for which this process ends in 1 are happy numbers.

		Example: 19 is a happy number

		12 + 92 = 82
		82 + 22 = 68
		62 + 82 = 100
		12 + 02 + 02 = 1
	}
*/
#include <iostream>
#include <unordered_map>

using namespace std;

bool isHappy(int n) {
	unordered_map<int, bool> mp;

	while(1) {
//		cout << n << endl;
		if(mp.find(n) != mp.end()) {
			return false;
		}

		mp[n] = true;
		int m = 0;
		while(n != 0) {
			int tmp = 0;
			tmp = n%10;
			m += tmp*tmp;
			n /= 10;
		}	

		if(m == 1) {
			return true;
		}

		n = m;		
	}
}

int main(int argc, char *argv[]) {
	int t = 19;
	cout << t << " isHappy:" << isHappy(t) << endl;

	t = 20;
	cout << t << " isHappy:" << isHappy(t) << endl;

	t = 21;
	cout << t << " isHappy:" << isHappy(t) << endl;

	t = 22;
	cout << t << " isHappy:" << isHappy(t) << endl;
	
	return 0;
}


