#include <iostream>
#include <vector>
#include <string>

using namespace std;

void myswap(char &a, char &b) {
	char t = a;
	a = b;
	b = t; 
}

#if 0
bool backTracking(int x, vector<char> &c, int n, int &k, string &s) {
	if(x == n) {
		k--;
		if(k == 0) {
			for(int i = 0; i < n; i++) {
				s += c[i];
			}
			return true;
		} else {
			return false;
		}
	}	

	for(int i = x; i < n; i++) {
		swap(c[x], c[i]);
		if(backTracking(x+1, c, n, k, s)) {
			return true;
		}
		swap(c[x], c[i]);
	}	
}

string getPermutation(int n, int k) {
	vector<char> c;
	for(int i = 0; i < n; i++) {
		c.push_back(i+'1');
	}	

	string s = "";
	backTracking(0,c, n, k, s);
	return s;
}
#endif
bool backTracking(string &s, int x, int n, int &k) {
	if(x == n) {
//		cout << "k = " << k  << ", " << s << endl;
		k--;
		if(k == 0) {
			return true;
		} else {
			return false;
		}
	}	

	for(int i = x; i < n; i++) {
		myswap(s[x], s[i]);
		if(backTracking(s, x+1, n, k)) {
			return true;
		}
		myswap(s[x], s[i]);
	}	
}

string getPermutation(int n, int k) {
	string s = "";
	for(int i = 0; i < n; i++) {
		s += (i+'1');
	}	

	backTracking(s, 0, n, k);
	return s;
}

int main(int argc, char *argv[]) {
	cout << getPermutation(2, 2) << endl;
	cout << getPermutation(3, 2) << endl;
	cout << getPermutation(9, 100) << endl;
	return 0;
}

