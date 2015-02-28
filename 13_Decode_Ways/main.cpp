#include <iostream>
#include <string>

using namespace std;

int numDecodings(string s) {
	if(s.empty() || s[0] == '0') return 0;

	int num = s.size();
	int *N = new int[num];
	int ret = 0;
	int d =0,p= 0;

	s[0] == '0' ? N[0] = 0:N[0] = 1;
	for(int i = 1; i < num; i++) {
		if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') {
			delete[] N;
			return 0;
		}
		if(i>1 && s[i-2] != '0') {
			p = (s[i-2]-'0') * 10 + (s[i-1]-'0');
		} else {
			p = 30;
		}
		d = (s[i-1]-'0') * 10 + (s[i]-'0');
		if(s[i] == '0' || s[i-1] == '0' || d > 26) {
			if(s[i] == '0' && p <= 26) {
				N[i] = N[i-1] -1;
			} else {
				N[i] = N[i-1];
			}
		} else {
			if ( i > 1 ) {
				N[i] = N[i-2] + N[i-1];
			} else {
				N[i] = N[i-1] + 1;
			}
		} 
	}

	ret = N[num-1];
	delete[] N;

	return ret;
}

int main(int argc, char *argv[])
{
#if 1
	string a("12"); // 2
	cout << numDecodings(a) << endl;
	
	// first WA
	string b("0"); // 0
	cout << numDecodings(b) << endl;

	// Second WA
	string c("10"); // 1 
	cout << numDecodings(c) << endl;

	// Third WA
	string d("012"); // Expected 0
	cout << numDecodings(d) << endl;

	string f("1012"); // 2
	cout << numDecodings(f) << endl;

	string g("704"); // 0
	cout << numDecodings(g) << endl;
#endif
	// four WA
	string h("110"); // 1
	cout << numDecodings(h) << endl;

	// five WA
	string j("1010"); // 1
	cout << numDecodings(j) << endl;

	// six WA
	string k("1212"); // 5
	cout << numDecodings(k) << endl;

	return 0;
}
