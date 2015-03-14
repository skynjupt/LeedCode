/*
	https://leetcode.com/problems/min-stack/
	{
		Design a stack that supports push, pop, top, and retrieving the minimum element 
		in constant time.

		push(x) -- Push element x onto stack.
		pop() -- Removes the element on top of the stack.
		top() -- Get the top element.
		getMin() -- Retrieve the minimum element in the stack.
	}
*/

#include <iostream>
#include <deque>
#include <stack>
#include <limits.h>

using namespace std;

#if 0
#define MAX 1000

int cur = 0;
int A[MAX]; 

void push(int x) {
	if(cur < 0 || cur >= MAX) {
		return;
	}
	A[cur++] = x;
}

void pop() {
	if(cur <= 0) {
		return;
	}
	cur--;
}

int top() {
	if(cur <= 0) {
		return -1;
	}	
	return A[cur-1];
}

int getMin() {
	int min_value = A[0];
	for(int i = 1; i < cur; i++) {
		if(A[i] < min_value) {
			min_value = A[i];	
		}	
	}
	return min_value;
}
// #else
deque<int> st;
deque<int> mi;

void push(int x) {
	st.push_back(x);
	if(mi.empty() || x <= mi.back())
		mi.push_back(x);
}

void pop() {
	if(st.empty()) {
		return;
	}
	if(st.back() == mi.back())
		mi.pop_back();
	st.pop_back();
}

int top() {
	if(st.empty()) {
		return -1;
	}	
	return st.back();
}

int getMin() {
	if(mi.empty()) 
		return -1;
	return mi.back();
}
#else
stack<long long> st;
long long min_value = 0;
void push(int x) {
	if(st.empty()) {
		st.push(0L);
		min_value = x;
	} else {
		st.push(x-min_value);
		if (x<min_value) min_value = x;
	}
}

void pop() {
	if(st.empty()) {
		return;
	}
	long long top = st.top();
	st.pop();
	if(top < 0)
		min_value = min_value - top;
}

int top() {
	long long top = st.top();
	if(top > 0) {
		return (int)(top+min_value);
	} else {
		return min_value;
	}
}

int getMin() {
	return min_value;
}

#endif
	
int main(int argc, char *argv[])
{
# if 0
	push(6);
	push(5);
	push(3);
#else
	push(INT_MAX);
	push(INT_MIN);
#endif
	cout << "min_value=" << getMin() << ",top=" << top() << endl;
	pop();
	cout << "min_value=" << getMin() << ",top=" << top() << endl;

	return 0;
}
