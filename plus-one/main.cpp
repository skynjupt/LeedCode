/*
	https://leetcode.com/problems/plus-one/
	{
	Given a non-negative number represented as an array of digits, 
	plus one to the number.

	The digits are stored such that the most significant digit is at the head of the list.
	}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
	int len = digits.size();
	if(len <= 0) {
		return digits;
	}	

	digits[len-1] = digits[len-1] + 1;
	for(int i=len-1; i >= 0; i--) {
		int t = digits[i];
		if(t == 10) {
			digits[i] = 0;
			if(i-1 >= 0) {
				digits[i-1] = digits[i-1] + 1;
			} else { // 0000,0000
				digits.push_back(1); // 0000,0000,1
				reverse(digits.begin(), digits.end()); // 1,0000,0000		
				break;
			}
		} else {
			digits[i] = t;
			break;
		}
	}
	return digits;
}

void printVector(vector<int> &digits) {
	int len = digits.size();
	for(int i = 0; i < len; i++) {
		cout << digits[i] << ",";
	}
	cout << endl;
}

vector<int> createVector(int a[], int n){
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}	
	return v;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4};
	vector<int> v = createVector(a, sizeof(a)/sizeof(a[0]));
	v = plusOne(v);
	printVector(v);

	int b[] = {9,9,9, 9};
	v = createVector(b, sizeof(b)/sizeof(b[0]));
	v = plusOne(v);
	printVector(v);

	int c[] = {9,1,9};
	v = createVector(c, sizeof(c)/sizeof(c[0]));
	v = plusOne(v);
	printVector(v);
		
	return 0;
}
