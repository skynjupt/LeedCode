/*
https://leetcode.com/problems/repeated-dna-sequences/
{
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, 
it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
}
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	vector<string> ret;
	unordered_map<int,int> m;
	int t = 0;
	for(int i = 0; i < s.length(); i++) {
		t = (t<<3|(s[i]&0x7)) & 0x3fffffff;
		if(m[t]++ == 1) {
			ret.push_back(s.substr(i-9,10));
		}	
	}	        
	return ret;
}

void myprint(vector<string> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> ret = findRepeatedDnaSequences(s);
	myprint(ret);	
	return 0;
}
