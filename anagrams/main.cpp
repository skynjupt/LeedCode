#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#if 0 
// i'dont understand anagrams
vector<string> anagrams(vector<string> &strs) {
	unordered_map<string, bool> mp;
	vector<string> ret;
	
	for(int i = 0; i < strs.size(); i++) {
		string tmp = strs[i];
		if(tmp.empty() || tmp.length() == 0) continue;
		int low = 0;
		int high = tmp.length()-1;
		bool flag = false;
		while(low < high) {
			string sub = tmp.substr(low, high-low+1);
			if(mp.count(sub) > 0) {
				if(mp[sub]) {
					flag = true;
				}
				break;
			}
			if(tmp[low] != tmp[high]) {
				break;
			}
			low++;
			high--;
		}
		if(flag || low >= high) {
			mp[tmp] = true;		
			ret.push_back(tmp);
		} else {
			mp[tmp] = false;
		}	
	}		
	return ret;
}
#endif


vector<string> anagrams(vector<string> &strs) {
	vector<string> ret;
	vector<string> sortedStrs = strs;
	unordered_map<string, vector<int>> map;
	int n = strs.size();
	for(int i = 0; i < n; i++) {
		sort(sortedStrs[i].begin(), sortedStrs[i].end());
		map[sortedStrs[i]].push_back(i);
	}

	for(auto it = map.begin(); it != map.end(); it++) {
		if(it->second.size() > 1) {
			for(int i = 0; i < it->second.size(); i++) {
				ret.push_back(strs[it->second[i]]);
			}
		}	
	}
	return ret;
}

void printVector(vector<string> &strs) {
	for(int i = 0; i < strs.size(); i++) {
		cout << strs[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	vector<string> strs;
	strs.push_back("test");
	strs.push_back("estt");
	strs.push_back("testset");
	strs.push_back("testtset");
	strs.push_back("testttattst");
	strs.push_back("t");
	strs.push_back("tst");
	strs.push_back("");
	strs = anagrams(strs);
	printVector(strs);	
	return 0;
}
