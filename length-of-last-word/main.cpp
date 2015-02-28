#include <iostream>

using namespace std;

int lengthOfLastWord(const char *s) {
	if(s == NULL) {
		return 0;
	}
	int t = 0, len = 0;
	for(int i = 0; s[i] != '\0'; i++) {
		if(s[i] != ' ') {
			t++;
			len = t;
		} else {
			t = 0;
		}
	}

	return len;
}

int main(int argc, char *argv[]) {
	cout << lengthOfLastWord("Hello World  H") << endl;
	return 0;
}
