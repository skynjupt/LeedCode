#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isOperator(string s) {
	if(s.compare("+") == 0 
		|| s.compare("-") == 0
		|| s.compare("*") == 0
		|| s.compare("/") == 0) {
		return true;
	} else {
		return false;
	}
}

#if 0
int evalRPN(vector<string> &tokens) {
	stack<int> st;
	int n = tokens.size();
	int a, b;
	for(int i = 0; i < n; i++) {
		if(tokens[i].length() > 1) {
			st.push(atoi(tokens[i].c_str()));
			continue;
		}
		switch(tokens[i][0]) {
		case '+':
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b+a);
			break;
		case '-':
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b-a);
			break;
		case '*':
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b*a);
			break;
		case '/':
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b/a);
			break;
		default:
			st.push(atoi(tokens[i].c_str()));
			break;
		}
	}	
	return st.top();		
}
#endif

int evalRPN(vector<string> &tokens) {
	stack<int> st;
	int n = tokens.size();
	for(int i = 0; i < n; i++) {
		if(isOperator(tokens[i])) {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			int result = 0;
			switch(tokens[i][0]) {
			case '+':
				result = b + a;
				break;
			case '-':
				result = b - a;
				break;
			case '*':
				result = b * a;
				break;
			case '/':
				result = b / a;
				break;
			}
			st.push(result);
		} else {
			st.push(atoi(tokens[i].c_str()));
		}
	}	
	return st.top();		
}

int main(int argc, char *argv[]) {
	vector<string> token1;
	token1.push_back("-1");	
	token1.push_back("1");	
	token1.push_back("*");	
	token1.push_back("-1");	
	token1.push_back("+");	
	cout << evalRPN(token1) << endl;
	return 0;
}
