#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#if 0
string addBinary(string a, string b) {
	string s = "";
	int n = a.length();
	int m = b.length();
	
	int i, j;
	int flag = 0;	
	char t;
	for(i=n-1, j=m-1; i >= 0 && j >= 0; i--, j--) {
		if(flag) {
			flag = 0;
			t = a[i] + b[j] + 1 - '0';	
		} else {
			t = a[i] + b[j] - '0';
		}
		if(t == '2') {
			s = '0' + s;		
			flag = 1;
		} else if( t == '3') {
			s = '1' + s;
			flag = 1;
		} else {
			s = t + s;
		}	
	}	

	while(i >= 0) {
		if(flag) {
			flag = 0;
			t = a[i] + 1;
		} else {
			t = a[i];
		}

		if(t == '2') {
			s = '0' + s;		
			flag = 1;
		} else {
			s = t + s;
		}	
		i--;	
	}
	while(j >= 0) {
		if(flag) {
			flag = 0;
			t = b[j] + 1;
		} else {
			t = b[j];
		}

		if(t == '2') {
			s = '0' + s;		
			flag = 1;
		} else {
			s = t + s;
		}
		j--;
	}

	if(flag) {
		s = '1' + s;
	}

	return s;	
}
#endif

string addBinary(string a, string b) {
	string result = "";
	int apos = a.size()-1;
	int bpos = b.size()-1;
	int adigit, bdigit, carry = 0;

	while(apos >= 0 || bpos >= 0 || carry == 1) {	
		adigit = bdigit = 0;
		if(apos >= 0) adigit = a[apos--] == '1';
		if(bpos >= 0) bdigit = b[bpos--] == '1';

		result = static_cast<char>(adigit ^ bdigit ^ carry + '0') + result;
		carry = adigit + bdigit + carry >= 2;
	}

	return result;
}

int main(int argc, char *argv[]) {
	cout << addBinary("11", "111") << endl;
	cout << addBinary("101", "1") << endl;
	cout << addBinary("1", "111") << endl;

	return 0;
}
