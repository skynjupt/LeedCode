/*
https://leetcode.com/problems/valid-parentheses/
{
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" 
are all valid but "(]" and "([)]" are not.
}
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	int n = s.size();
	if(n <= 0) {
		return false;
	}
	stack<char> st;
	st.push(s[0]);
	for(int i = 1; i < n; i++) {
		char t = s[i];
		switch(t) {
		case '{':
		case '[':
		case '(':
			st.push(t);
			break;
		case '}':
		case ']':
		case ')':
			if(st.empty()) {
				return false;
			}
			char p = st.top();
			st.pop();
			if(t == '}' && p != '{') {
				return false;	
			} else if (t == ']' && p != '[') {
				return false;	
			} else if (t == ')' && p != '(') {
				return false;	
			}
			break;
		}
	}

	if(st.empty()) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	cout << "[] =>" << isValid("[]") << endl;
	cout << "[(]) =>" << isValid("[(])") << endl;
	cout << "[()] =>" << isValid("[()]") << endl;
	cout << "[]() =>" << isValid("[]()") << endl;
	cout << "[]()( =>" << isValid("[]()(") << endl;
	cout << "[]()) =>" << isValid("[]())") << endl;
	cout << "[](){} =>" << isValid("[](){}") << endl;
	return 0;
}
