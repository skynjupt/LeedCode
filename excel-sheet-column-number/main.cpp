#include <iostream>

using namespace std;

int titleToNumber(string s) {
	int n = s.size();
	int number = 0;
	for(int i = 0; i < n; i++) {
		number = number*26 + s[i]-'A'+1;
	}	
	return number;
}

int main(int argc, char *argv[]) {
	cout << "B->" << titleToNumber("B") << endl;
	cout << "AA->" << titleToNumber("AA") << endl;
	cout << "AB->" << titleToNumber("AB") << endl;
	return 0;
}
