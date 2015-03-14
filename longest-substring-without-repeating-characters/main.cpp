/*
	https://leetcode.com/problems/longest-substring-without-repeating-characters/
	{
		Given a string, find the length of the longest substring without repeating characters. 
		For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
		which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
	}
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0
int lengthOfLongestSubstring(string s) {
	int n = s.length();
	if( n <= 1) {
		return n;
	}

	int max = 1;
	int slow = 0;
	int fast = slow+1;
	for(;fast < n && n-slow > max; fast++) {
		int i = slow;
		for( ; i < fast; i++) {
			if(s[i] == s[fast]) {
				break;
			}
		}
		if(i == fast) {
			if(fast-slow+1 > max) {
				max = fast-slow+1;
			}
		} else {
			slow = i+1;
		}
	}
	return max;
}
#endif

int lengthOfLongestSubstring(string s) {
	vector<int> mp(256, -1);
	
	int n = s.length();
	int m = 0;
	int longest = 0;

	for(int i = 0; i < n; i++) {
		m = max(mp[s[i]]+1, m);
		mp[s[i]] = i;	
		if(i-m+1 > longest) {
			longest = i-m+1;
		}	
	}

	return longest;
}

int main(int argc, char *argv[]) {
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	cout << lengthOfLongestSubstring("bbbbb") << endl;
	cout << lengthOfLongestSubstring("au") << endl;
	return 0;
}
