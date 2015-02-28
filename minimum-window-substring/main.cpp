#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string S, string T) {
	if(S.empty() || T.empty()) {
		return "";
	}
	/*hashmap char -> how many char in T*/
	vector<int> mp(256, 0);
	/*flag: is char in T*/
	vector<bool> flag(256, false);
	/*how many are needed*/
	int count = T.length();

	for(int i = 0; i < count; i++) {
		mp[T[i]]--;
		flag[T[i]] = true;
	}

	int minLen = INT_MAX;
	int minIndex = 0;

	int n = S.length();
	int slow = 0;
	int fast = -1;

	while(slow < n && fast < n) {
		if(count) {
			fast++;
			mp[S[fast]]++;
			if( flag[S[fast]] && mp[S[fast]] <= 0 ) {
				count--;
			}
		} else {
			// check slow ~ fast 
			if( fast-slow+1 < minLen) {
				minLen = fast-slow+1;
				minIndex = slow;
			}
			mp[S[slow]]--;
			if( flag[S[slow]] && mp[S[slow]] < 0) {
				count++;
			}	
			slow++;
		}
	}	

	if(minLen == INT_MAX) {
		return "";
	}

	return S.substr(minIndex, minLen);	
}

int main(int argc, char *argv[]) {
	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
	cout << minWindow("ADOBECODEBANC", "ABCK") << endl;
	cout << minWindow("ADOBECODEBANC", "A") << endl;
	return 0;
}
