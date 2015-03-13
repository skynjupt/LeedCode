/*
	https://leetcode.com/problems/interleaving-string/
	{
		Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

		For example,
		Given:
		s1 = "aabcc",
		s2 = "dbbca",

		When s3 = "aadbbcbcac", return true.
		When s3 = "aadbbbaccc", return false.
	}
*/
#include <iostream>
#include <string>

using namespace std;

#if 0
/*
Time Limit Exceeded:
"bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
 */
bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.length();
	int n2 = s2.length();
	int n3 = s3.length();
	if(n3 != n1+n2) {
		return false;
	}

	if(n1 == 0 || n2 == 0) {
		return n1 == 0 ? s2.compare(s3) == 0 : s1.compare(s3) == 0;
	}

	if(s3[0] == s1[0] || s3[0] == s2[0]) {
		if(s3[0] == s1[0] && s3[0] == s2[0]) {
			string t1 = s1;
			string t3 = s3;
			if(isInterleave(t1.erase(0,1), s2, t3.erase(0,1))) {
				return true;	
			} 
			t1 = s2;
			t3 = s3;
			if(isInterleave(s1, t1.erase(0,1), t3.erase(0,1))) {
				return true;	
			}
			return false;
		} else if(s3[0] == s1[0]) {
			return isInterleave(s1.erase(0,1), s2, s3.erase(0,1));
		} else if(s3[0] == s2[0]) {
			return isInterleave(s1, s2.erase(0,1), s3.erase(0,1));
		}
	} else {
		return false;
	}	
}
#endif


bool isInterleave(string s1, string s2, string s3) {
	if(s1.length() + s2.length() != s3.length()) {
		return false;
	}

	bool dp[s1.length()+1][s2.length()+1];
	for(int i = 0; i <= s1.length(); i++) {
		for(int j = 0; j <= s2.length(); j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = true;
			} else if( i == 0 ) {
				dp[i][j] = dp[i][j-1] && s2[j-1] == s3[j-1];
			} else if( j == 0 ) {
				dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i-1];
			} else {
				dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
			}
		}
	}
	return dp[s1.length()][s2.length()];
}


int main(int argc, char *argv[]) {
	cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
	cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
	string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	cout << isInterleave(s1, s2, s3) << endl;
	return 0;
}
