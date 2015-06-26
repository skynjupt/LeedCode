/*
https://leetcode.com/problems/word-ladder-ii/
{
Given two words (start and end), and a dictionary, 
find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
}
*/

#include <iostream>
#include <string>
#include <queue>	
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

vector<vector<string> > vv;
unordered_map<string, vector<string>> m;

void dfs(string start, string end, vector<string> &v) {
	if(start == end) {
		v.insert(v.begin(), end);
		vv.push_back(v);	
		v.erase(v.begin());
		return;
	}

	v.insert(v.begin(), end);
	for(int i = 0; i < m[end].size(); i++) {
		dfs(start, m[end][i], v);
	}
	v.erase(v.begin());
}

/*bfs + dfs*/
vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
	queue<string> q;
	unordered_map<string, int> d;
	int min = INT_MAX;

	q.push(start);
	dict.insert(end);

	for(auto it = dict.begin(); it != dict.end(); it++) {
		d[*it] = INT_MAX;
	}
	d[start] = 0;

	while(!q.empty()) {
		string word = q.front();
		q.pop();
		int step = d[word]+1;
		if(step > min) {
			break;
		}
		for(int ii = 0; ii < word.length(); ii++) {
			for(int jj = 0; jj < 26; jj++) {
				string tmp = word;
				tmp[ii] = 'a'+jj;
				if(dict.count(tmp) > 0) {
					if(step > d[tmp]) {
						continue;
					} else if(step < d[tmp]) {
						d[tmp] = step; 
						q.push(tmp);
					}

					m[tmp].push_back(word);

					if(tmp == end) {
						min = step;	
					}
				}
			}
		}	
	}

	// dfs
	vector<string> v;
	dfs(start, end,v);	
	
	return vv; 
}

void printvv(vector<vector<string> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {

	vv.clear();
	m.clear();
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
	vector<vector<string> > tt = findLadders(start, end, dict);
	printvv(tt);		

	vv.clear();
	m.clear();
	start = "a";
	end = "c";
	dict = {"a", "b", "c"};
	tt = findLadders(start, end, dict);
	printvv(tt);		

	vv.clear();
	m.clear();
	start = "red";
	end = "tax";
	dict = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
	tt = findLadders(start, end, dict);
	printvv(tt);		

	return 0;
}
