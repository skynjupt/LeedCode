#include <iostream>
#include <climits>
#include <string>

using namespace std;

int myatoi(string str) {
	int ret = 0; 
	int n = str.length();
	if(n == 0) {
		return 0;
	}
	int sign = 1;
	int index = 0;

	while(str[index] == ' ' || str[index] == '\t') {
		index++;	
	}

	if(str[index] == '-') {
		sign = -1;
		index++;
	} else if(str[index] == '+') {
		sign = 1;
		index++;
	} 
	
	while(index < n) {
		if(str[index] >= '0' && str[index] <= '9') {
			if(ret > INT_MAX / 10 || ret == INT_MAX / 10 && str[index] > '7') {
				return sign == 1 ? INT_MAX:INT_MIN; 
			}
			ret = ret * 10 + (str[index++] - '0');
		} else {
			break;
		}
	}

	return sign * ret;
}

int main(int argc, char *argv[]) {
#if 1
	cout << myatoi("123") << endl;
	cout << myatoi("123ab") << endl;
	cout << myatoi("-123ab") << endl;
	cout << myatoi("+123ab") << endl;
	cout << myatoi("12+123ab") << endl;
	cout << myatoi("abc12+123ab") << endl;
	cout << myatoi("-abc12+123ab") << endl;
	cout << myatoi("+0ab") << endl;
	cout << myatoi("-0ab") << endl;
#endif
	cout << myatoi("-12345678923456") << endl;
	cout << myatoi("     123") << endl;
	cout << myatoi("    10522545459") << endl;

	return 0;
}
