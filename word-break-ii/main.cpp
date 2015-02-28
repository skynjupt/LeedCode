#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> wordBreak(string s, unordered_set<string> &dict) {
	bool dp[1000][1000] = {false};
	vector<vector<string> > vv;
	vector<string> v;
	int len = s.length();
	dp[len-1][1] = (dict.find(s.substr(len-1, 1)) != dict.end());
	if(dp[len-1][1]) {
		v.push_back(s.substr(len-1,1));
	}
	vv.push_back(v);
	for(int i=len-2; i>=0; i--) {
		v.clear();
		for(int l=1; i+l<=len; l++) {
			string t = s.substr(i, l);
			bool flag = false;
			flag |= (dict.find(t) != dict.end()); 
			if(i+l != len) {
				flag = flag && dp[i+l][len-i-l];
				if(flag) {
					for(int j = 0; j < vv[len-i-l-1].size(); j++) {
						string tmp = t + " " + vv[len-i-l-1][j];
						v.push_back(tmp);	
					}	
				}	
			} else if(flag) {
				v.push_back(t);
			}
			dp[i][len-i] |= flag;
		}
		vv.push_back(v);
	}
	return vv[len-1];
}


int main(int argc, char *argv[]) {
	unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
	vector<string> v = wordBreak("catsanddog", dict);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}
