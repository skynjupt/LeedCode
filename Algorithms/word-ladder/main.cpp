/*
https://leetcode.com/problems/word-ladder/
{
Given two words (start and end), and a dictionary, 
find the length of shortest transformation sequence from start to end, 
such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
}
*/

#include <iostream>
#include <string>
#include <queue>	
#include <unordered_set>
#include <unordered_map>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
	queue<string> q;
	unordered_map<string, int> m;

	m[start] = 1;
	if(start == end) goto RET;

	q.push(start);
	while(!q.empty()) {
		string word = q.front();
		q.pop();
		for(int ii = 0; ii < word.length(); ii++) {
			for(int jj = 0; jj < 26; jj++) {
				string tmp = word;
				tmp[ii] = 'a'+jj;
				if(tmp == end) {
					m[tmp] = m[word]+1;
					goto RET;
				}
				if(dict.count(tmp) > 0 && m[tmp] == 0) {
					m[tmp] = m[word]+1;
					q.push(tmp);
				}
			}
		}	
	}
RET:
	return m[end]; 
}

int main(int argc, char *argv[]) {
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
	cout << ladderLength(start, end, dict) << endl;
	return 0;
}
