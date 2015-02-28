#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> ans;
	if(S.empty() || L.empty()) {
		return ans;	
	}

	unordered_map<string, int> mp;
	int count = L.size();
	for(int i = 0; i < count; i++) {
		mp[L[i]]++;
	}
	
	int wl = L[0].size();
	for(int i = 0; i < wl; i++) {
		unordered_map<string, int> tp;
		int tcnt = 0;
		int low = i;
		for(int fast = i; fast < S.length(); fast+=wl) {
			string w = S.substr(fast, wl);	
			if(mp.count(w) > 0) {
				tp[w]++;	
				if(tp[w] <= mp[w]) {
					tcnt++;		
				} else {
					do {
						string tstr = S.substr(low, wl);
						tp[tstr]--;
						low+=wl;
						if(w.compare(tstr) == 0) {
							break;
						}
						tcnt--;
					}while(1);
				}
				
				if(tcnt == count) {
					ans.push_back(low);					
					tp[S.substr(low, wl)]--;
					tcnt--;
					low += wl;
				}
			} else {
				tp.clear();
				tcnt = 0;		
				low = fast+wl;
			}
		}	
	}	

	return ans;
}

void printVector(vector<int> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	vector<string> dict = { "foo", "bar" };
	string S = "barfoothefoobarman"; 
	vector<int> ans = findSubstring(S, dict);
	printVector(ans);

	dict = { "a", "b" };
	S = "aaa"; 
	ans = findSubstring(S, dict);
	printVector(ans);

	dict = { "a", "b", "a" };
	S = "abababab"; 
	ans = findSubstring(S, dict);
	printVector(ans);
	return 0;
}
