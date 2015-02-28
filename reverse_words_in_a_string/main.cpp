#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

#if 1
void reverseWords(string &s) {
	stack<string> st; 
	int i = 0, b = 0, e = 0;
	int len = s.size();
	while(i < len) {
		while(i < len && s[i] == ' ') {
			i++;	
		}
		if( i >= len ) break;
		b = i;
		while(i < len && s[i] != ' ') {
			i++;	
		}
		e = i;
		st.push(s.substr(b, e-b));
	}
	string t;
	while(!st.empty()) {
		t += st.top();
		st.pop();	
		if(!st.empty()) {
			t += " ";
		}
	}
	s = t;
}
#else
void reverseWords(string &s) {
	vector<string> ve;
	int i = 0, b = 0, e = 0;
	int len = s.size();
	while(i < len) {
		while(i < len && s[i] == ' ') {
			i++;	
		}
		if( i >= len ) break;
		b = i;
		while(i < len && s[i] != ' ') {
			i++;	
		}
		e = i;
		string tt = s.substr(b, e-b);
		ve.push_back(tt);
	}
	string t = "";
	for(i = ve.size()-1; i >= 0; i--) {
		t += ve[i];
		if(i != 0) {
			t += " ";
		}
	}

	s = t;
}
#endif
int main(int argc, char *argv[])
{
	string s("the sky is blue");
	reverseWords(s);
	cout << s << endl;

	string s2("    2323  the sky is blue     ");
	reverseWords(s2);
	cout << s2 << endl;
#if 1
	// output: hi , expect hi!
	string s3("hi!");
	reverseWords(s3);
	cout << s3 << endl;
#endif

	return 0;
}
