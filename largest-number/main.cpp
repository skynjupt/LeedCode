#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
void qsort(vector<int> &num, int left, int right) {

}
*/

string largestNumber(vector<int> &num) {
	vector<string> strs;
	for(auto i:num) {
		strs.push_back(to_string(i));
	}
	sort(begin(strs), end(strs), [](const string &s1, const string &s2){ return s1+s2>s2+s1; });
//	sort(strs.begin(), strs.end(), [](const string &s1, const string &s2){ return s1+s2>s2+s1; });
	string res;
	for(auto s:strs) {
		res+=s;
	}

	while(res.length()>1 && res[0]=='0') {
		res.erase(0,1);
	}

	return res;
}

vector<int> creteV(int a[], int n) {
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	return v;
}

int main(int argc, char *argv[]) {
	int a[] = {3, 30, 34, 5, 9};
	vector<int> t = creteV(a, sizeof(a)/sizeof(a[0]));
	cout << largestNumber(t) << endl;

	int b[] = {0, 0, 0, 0, 0};
	t = creteV(b, sizeof(b)/sizeof(b[0]));
	cout << largestNumber(t) << endl;
	return 0;
}
