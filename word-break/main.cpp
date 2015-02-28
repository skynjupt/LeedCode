#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
	bool dp[100][100] = {false};
	int len = s.length();	
	dp[len-1][1] = (dict.find(s.substr(len-1, 1)) != dict.end());		
	for(int i=len-2; i>=0; i--) {
		for(int l=1; i+l<=len; l++) {
			string t = s.substr(i, l);
			dp[i][l] |= (dict.find(t) != dict.end());	
			if(i+l != len) {
				dp[i][len-i] |= dp[i][l] && dp[i+l][len-i-l];
			}
		}
	}
	return dp[0][len];
}

int main(int argc, char *argv[]) {
	unordered_set<string> dict = {"leet", "code"};
	cout << wordBreak("leetcode", dict) << endl;	
	cout << wordBreak("leecode", dict) << endl;	
	return 0;
}
