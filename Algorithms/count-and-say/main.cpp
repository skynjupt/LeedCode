/*
	https://leetcode.com/problems/count-and-say/
	{
		The count-and-say sequence is the sequence of integers beginning 
		as follows:
		1, 11, 21, 1211, 111221, ...

		1 is read off as "one 1" or 11.
		11 is read off as "two 1s" or 21.
		21 is read off as "one 2, then one 1" or 1211.
		Given an integer n, generate the nth sequence.

		Note: The sequence of integers will be represented as a string.
	}
*/

#include <iostream>

using namespace std;

string countAndSay(int n) {
	if(n == 1) {
		return "1";
	}

	string sub = countAndSay(n-1);
	string str = "";	
	int len = sub.length();
	for(int i = 0; i < len; ) {
		int cnt = 1;
		for(int j = i+1; j < len; j++) {
			if(sub[i] != sub[j]) {
				break;
			}
			cnt++;
		}
		str += (cnt+'0');
		str += sub[i];	
		i += cnt;
	}
	
	return str;
}

int main(int argc, char *argv[]) {
	cout << countAndSay(1) << endl;
	cout << countAndSay(4) << endl;
	cout << countAndSay(7) << endl;
	cout << countAndSay(8) << endl;
	return 0;
}
