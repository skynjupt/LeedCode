#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	string rets = "";
	if(strs.empty()) {
		return rets;
	}
	int offset = 0;
	int n = strs.size();

	do {
		int i;
		for(i = 0; i < n; i++) {
			if(offset >= strs[i].length() 
				|| offset >= strs[0].length()
				|| strs[i][offset] != strs[0][offset]) {
				break;
			}	
		}
		if(i < n) {
			break;
		}
		rets += strs[0][offset++];
	} while(1);

	return rets;	
	
}

int main(int argc, char *argv[]) {
	vector<string> strs;
	strs.push_back("testPre");
	strs.push_back("testtre");
	strs.push_back("teskre");
//	strs.push_back("");
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}
