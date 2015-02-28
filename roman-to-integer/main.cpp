#include <iostream>
#include <string>
#include <map>

using namespace std;

#if 0
int romanToInt(string s) {
	map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	int ret = 0;
	int c = 0;
	int n = s.size();
	char t = s[0];
	ret += m[s[0]];		
	
	for(int i = 1; i < n; i++) {
		ret += m[s[i]];
		if(m[s[i]] > m[t]) {
			c += m[t];
		}		
		t = s[i];	
	}

	return ret-2*c;
}
#endif


int romanToInt(string s) {
	int res = 0;
	for(int i = s.length()-1; i >= 0; i--) {
		char c = s[i];
		switch(c) {
		case 'I':
			res += (res >= 5 ? -1 : 1);
			break;
		case 'V':
			res += 5;
			break;
		case 'X':
			res += 10 * (res >= 50 ? -1 : 1);
			break;
		case 'L':
			res += 50;
			break;
		case 'C':
			res += 100 * (res >= 500 ? -1 : 1);
			break;
		case 'D':
			res += 500;
			break;
		case 'M':
			res += 1000;
			break;
		}
	}
	return res;
}

int main(int argc, char *argv[]) {
	cout << "I ->" << romanToInt("I") << endl;
	cout << "IV ->" << romanToInt("IV") << endl;
	cout << "VII ->" << romanToInt("VII") << endl;
	cout << "MMMCMXCIX ->" << romanToInt("MMMCMXCIX") << endl;
	return 0;
}
