/*
	https://leetcode.com/problems/palindrome-number/
	{
		Determine whether an integer is a palindrome. Do this without extra space.
	}
*/

#include <iostream>

using namespace std;

#if 0 // Wrong Answer
bool isPalindrome(int x) {
	if(x < 0) return false;
	int t = x;
	int c = 1;
	while(t/10 != 0) {
		t = t / 10;
		c++;
	}	
	int y = x % 10;
	if(t == y) {
		if(c == 1) {
			return true;
		} else {
			int cnt = t;
			while(--c) {
				cnt *= 10;
			}
			x -= cnt;
			x = x/10;
			return isPalindrome(x);
		}
	} else {
		return false;
	}

}
#endif

bool isPalindrome(int x) {
	if(x < 0) return false;
	long long d = 10, e = 10;
	while(x / d) d *= 10;
	while(d > e) {
		if( (x%d)/(d/10) != (x%e)/(e/10) ) {
			return false;
		}
		d /= 10;
		e *= 10;	
	}
	return true;
}
int main(int argc, char *argv[]) {
	cout << isPalindrome(1234321) << endl;
	cout << isPalindrome(12345321) << endl;
	cout << isPalindrome(12344321) << endl;
	cout << isPalindrome(1000021) << endl;
	cout << isPalindrome(0) << endl;
	return 0;
}
