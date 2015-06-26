#include <iostream>
#include <vector>

using namespace std;

void printV(vector<int> v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

bool backtrack(int x, int max, vector<int> &v) {
	if(x == max) {
		return true;
	}

	for(int i = x; i < max; i++) {
		int t = v[x-1] ^ v[i];
		if((t & (t-1)) == 0) {
			swap(v[x], v[i]);
			if(backtrack(x+1, max, v)) {
				return true;
			}	
			swap(v[x], v[i]);
		}
	}

	return false;
}

vector<int> grayCode(int n) {
	int max = 2 << (n-1);
	vector<int> v;
	for(int i = 0; i < max; i++) {
		v.push_back(i);	
	}

	backtrack(1, max, v);		
	return v;	
}


int main(int argc, char *argv[]) {
	vector<int> v = grayCode(6);
	printV(v);
	return 0;
}
