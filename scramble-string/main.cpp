/*
https://leetcode.com/problems/scramble-string/
{
Given a string s1, we may represent it as a binary tree by partitioning it 
to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, 
it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", 
it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
}
*/

#include <iostream>
#include <string>

using namespace std;

/* Time Limit Exceeded:
	"abcdefghijklmn", "efghijklmncadb"
 */
#if 0
bool backTracking(string s1, string s2, int t) {
	if(t == s1.length()) {
		return s2.compare(s1) == 0;
	}
	for(int i = t; i < s1.length(); i++) {
		swap(s1[t],s1[i]);	
		if(backTracking(s1, s2, t+1)) {
			return true;
		} 
		swap(s1[t],s1[i]);
	}
	return false;
}
#endif

#if 1
bool backTracking(string s1, string s2, int t) {
	if(t == s1.length()) {
		return s2.compare(s1) == 0;
	}
	for(int i = t; i < s1.length(); i++) {
		swap(s1[t],s1[i]);	
		if(t > 0 && s2.compare(0, t, s1, 0, t) != 0) {
			swap(s1[t],s1[i]);	
			continue;
		}
		if(backTracking(s1, s2, t+1)) {
			return true;
		} 
		swap(s1[t],s1[i]);
	}
	return false;
}
#endif

bool isScramble(string s1, string s2) {
	return backTracking(s1, s2, 0);
}

int main(int argc, char *argv[]) {
//	cout << isScramble("abc", "bca") << endl;
//	cout << isScramble("abc", "bda") << endl;
//	cout << isScramble("great", "rgeat") << endl;
//	cout << isScramble("great", "rgtae") << endl;
//	cout << isScramble("abcdefghijklmn", "efghijklmncadb") << endl;
	cout << isScramble("abcd", "bdac") << endl;
	return 0;
}
