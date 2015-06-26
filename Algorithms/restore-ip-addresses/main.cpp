/*
https://leetcode.com/problems/restore-ip-addresses/
{
Given a string containing only digits, restore it by returning all possible valid IP 
address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
}
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gv;
vector<string> tv;
int cnt;
/*
Input:	"010010"
Output:	["0.1.0.010","0.1.00.10","0.1.001.0","0.10.0.10","0.10.01.0","0.100.1.0","01.0.0.10","01.0.01.0","01.00.1.0","010.0.1.0"]
Expected:	["0.10.0.10","0.100.1.0"]
*/
#if 0 // Wrong Answer
void backTracking(int a, string s) {
	int len = s.length();
	if(a >= len && cnt == 4) {
		string tmp = "";
		for(int i = 0; i < 4; i++) {
			tmp += tv[i];
			if(i < 3) {
				tmp += ".";	
			}
		}	
		gv.push_back(tmp);
	}

	for(int i = 1; i < 4 && a+i <= len && cnt < 4; i++) {
		int t = 0;
		for(int j = 0; j < i; j++) {
			t = 10*t + s[a+j] - '0';
		}		
		if( t >= 0 && t <= 255) {
			if(tv.empty() || tv.size() <= cnt) {
				tv.push_back(s.substr(a, i));
			} else {
				tv[cnt] = s.substr(a, i);
			}
			cnt++;
			backTracking(a+i, s);
			cnt--;
		}
	}
}
#endif

bool isValid(string s) {
	int len = s.length();
	int i = 0;
	for(i = 0; i < len; i++) {
		if(s[i] != '0') {
			break;
		}
	}

	if(i > 0 && len > 1) {
		return false;
	}

	int t = 0;
	for(i = 0; i < len; i++) {
		t = 10*t + s[i] - '0';
	}

	if( t >= 0 && t <= 255) {
		return true;
	} else {
		return false;
	}
}

void backTracking(int a, string s) {
	int len = s.length();
	if(a >= len && cnt == 4) {
		string tmp = "";
		for(int i = 0; i < 4; i++) {
			tmp += tv[i];
			if(i < 3) {
				tmp += ".";	
			}
		}	
		gv.push_back(tmp);
	}

	for(int i = 1; i < 4 && a+i <= len && cnt < 4; i++) {
		string sub = s.substr(a, i);
		if(isValid(sub)) {	
			if(tv.empty() || tv.size() <= cnt) {
				tv.push_back(sub);
			} else {
				tv[cnt] = sub; 
			}
			cnt++;
			backTracking(a+i, s);
			cnt--;
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	cnt = 0;
	backTracking(0, s);
	return gv;
}

void printV(vector<string> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

int main(int argc, char *argv[]) {
	//vector<string> t = restoreIpAddresses("25525511135");
	vector<string> t = restoreIpAddresses("010010");
	printV(t);
	return 0;
}
