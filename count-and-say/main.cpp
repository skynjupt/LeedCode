#include <iostream>

using namespace std;


string countAndSay(int n) {
	if(n == 1) {
		return "1";
	}

	string sub = countAndSay(n-1);
	string str = "";	
	int len = sub.length();
	for(int i = 0; i < len; ) {
		int cnt = 1;
		for(int j = i+1; j < len; j++) {
			if(sub[i] != sub[j]) {
				break;
			}
			cnt++;
		}
		str += (cnt+'0');
		str += sub[i];	
		i += cnt;
	}
	
	return str;
}

int main(int argc, char *argv[]) {
	cout << countAndSay(1) << endl;
	cout << countAndSay(4) << endl;
	cout << countAndSay(7) << endl;
	cout << countAndSay(8) << endl;
	return 0;
}
