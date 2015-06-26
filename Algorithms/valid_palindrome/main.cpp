// 2014-12-15
// https://leetcode.com/problems/valid-palindrome/
/*
{
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
}
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char toLow(char t) {
	if( 'A' <= t && t <= 'Z') {
		t = t-'A' + 'a';
	}
	return t;
}

bool isPalindrome(string s) {
	if(s.empty()) {
		return true;
	}	

	int len = s.length();
	int i = 0;
	int j = len-1;
	char l,r;
	do {
		while(i<len && !isalnum(s[i])) i++;
		while(j>= 0 && !isalnum(s[j])) j--;
		
		if(i>= len || j < 0 || i >= j) break; 
		l = toLow(s[i]);
		r = toLow(s[j]);
		if(l != r) break;
		i++;
		j--;
	} while(1);
	if( i >= j) { 
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	string a = "A man, a plan, a canal: Panama";
	cout << a << endl;
	cout << isPalindrome(a) << endl;
	string b = "race a car";
	cout << b << endl;
	cout << isPalindrome(b) << endl;
	return 0;
}
	
