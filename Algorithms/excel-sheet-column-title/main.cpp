/*
	https://leetcode.com/problems/excel-sheet-column-title/
	{
		Given a positive integer, return its corresponding column title as appear in an Excel sheet.

		For example:

		    1 -> A
		    2 -> B
		    3 -> C
		    ...
		    26 -> Z
		    27 -> AA
		    28 -> AB 
	}
*/
#include <iostream>
#include <algorithm>

using namespace std;

string convertToTitle(int n) {
	string ret;
	if(n <= 0) {
		return ret;	
	}

	int t = n;
	int a;
	while(t>0) {
		a = (t-1)%26;
		t = (t-1)/26;
		ret.push_back(a+'A');
	}	

	reverse(ret.begin(), ret.end());	
	return ret;
}

int main(int argc, char *argv[]) {
	cout << convertToTitle(1) << endl;
	cout << convertToTitle(25) << endl;
	cout << convertToTitle(26) << endl;
	cout << convertToTitle(27) << endl;
	cout << convertToTitle(52) << endl;
	cout << convertToTitle(53) << endl;
	return 0;
}
