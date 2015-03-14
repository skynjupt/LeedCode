/*
	https://leetcode.com/problems/palindrome-partitioning/
	{
		Given a string s, partition s such that 
		every substring of the partition is a palindrome.

		Return all possible palindrome partitioning of s.

		For example, given s = "aab",
		Return
		  [
		    ["aa","b"],
		    ["a","a","b"]
		  ]
	}
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string> > vv;
vector<string> v;
int cnt; 

bool isPalindrome(string s) {
	int len = s.length();
	int i = 0, j = len - 1;
	while(i < j) {
		if(s[i] != s[j]) {
			break;
		} else {
			i++;
			j--;
		}
	}

	if(i < j) {
		return false;
	} else {
		return true;
	}
}

void backTracking(int b, string s) {
	int len = s.length();
	if(b >= len) {
		vector<string> tmp;
		for(int i = 0; i < cnt; i++) {
			tmp.push_back(v[i]);
		}
		vv.push_back(tmp);
	}

	for(int j = 1; b+j <= len; j++) {
		string sub = s.substr(b, j);
		if(isPalindrome(sub)) {	
			if(v.empty() || v.size() <= cnt) {
				v.push_back(sub);
				cnt++;
			} else {
				v[cnt++] = sub;
			}	
			backTracking(b+j, s);	
			cnt--;
		}
	}
	
}

vector<vector<string> > partition(string s) {
	cnt = 0;
	backTracking(0, s);
	return vv;
}

void printVV(vector<vector<string> > &vv1) {
	for(int i = 0; i < vv1.size(); i++) {
		for(int j = 0; j < vv1[i].size(); j++) {
			cout << vv1[i][j] << ",";
		}
		cout << endl;
	}
}
	

int main(int argc, char *argv[]) {
//	partition("aab");
	vector<vector<string> > vv1 = partition("aaa");
	printVV(vv1);
	return 0;
}

