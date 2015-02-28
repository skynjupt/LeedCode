#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> convertVersion(string version) {
	vector<int> v;
	if(!version.empty()){
		int len = version.length();
		int t = 0;
		for(int i = 0; i <= len; i++) {
			if(version[i] == '.' || i == len) {
				v.push_back(t);
				t = 0;	
			} else {
				t = t*10 + version[i]-'0';
			}	
		}	
		
	}

	return v;
}

int compareVersion(string version1, string version2) {
	vector<int> v1, v2;
	v1 = convertVersion(version1);
	v2 = convertVersion(version2);
	int n1 = v1.size();
	int n2 = v2.size();
	int i = 0;
	int m = n1 > n2 ? n2 : n1;
	for(i = 0; i < m; i++) {
		if(v1[i] != v2[i]) {
			break;
		}
	}

	if(i >= m) {
		if(n1 > n2) {
			int i = 0;
			for(i = m; i < n1; i++)  {
				if(v1[i] != 0) {
					break;
				}
			}

			if( i < n1 ) {
				return 1;
			} else {
				return 0;
			}
		} else if(n2 > n1) {
			int i = 0;
			for(i = m; i < n2; i++)  {
				if(v2[i] != 0) {
					break;
				}
			}

			if( i < n2 ) {
				return -1;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	} else {
		if(v1[i] > v2[i]) {
			return 1;
		} else {
			return -1;
		}	
	}
	
}

/*
 "1.0" =  "1"
 */ 
int main(int argc, char *argv[]) {
	string v1 = "0.1";
	string v2 = "1.1";
	string v3 = "0.0.1";
	string v4 = "1.0";
	string v5 = "1";	
	cout << compareVersion(v1, v2) << endl;
	cout << compareVersion(v1, v1) << endl;
	cout << compareVersion(v2, v1) << endl;
	cout << compareVersion(v2, v3) << endl;
	cout << compareVersion(v1, v3) << endl;
	cout << compareVersion(v4, v5) << endl;
	cout << compareVersion(v5, v4) << endl;
	return 0;
}
