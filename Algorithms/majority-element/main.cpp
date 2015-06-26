/*
	https://leetcode.com/problems/majority-element/
	{
		Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

		You may assume that the array is non-empty and the majority element always exist in the array.
	}
*/
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &num) {
	if(num.empty()) {
		return -1;
	}
	int n = num.size();
	int candidate = num[0];
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		if(candidate == num[i]) {
			cnt++;
		} else if(cnt == 0){
			candidate = num[i];
		} else {
			cnt--;
		}
	}
	
	return candidate;
}

vector<int> createVector(int a[], int n) {
	vector<int> v;
	if(n <= 0) {
		return v;
	}
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);
	}
	return v;
}

int main(int argc, char *argv[]) {
	int a1[] = {1, 3, 3, 4, 4, 3, 3};
	vector<int> v = createVector(a1, sizeof(a1)/sizeof(a1[0]));
	cout << majorityElement(v) << endl;
	int a2[] = {1, 3, 3, 3, 3, 4, 4};
	v = createVector(a2, sizeof(a2)/sizeof(a2[0]));
	cout << majorityElement(v) << endl;
	int a3[] = {4, 3, 3, 4, 4, 3, 3};
	v = createVector(a3, sizeof(a3)/sizeof(a3[0]));
	cout << majorityElement(v) << endl;
	int a4[] = {3, 3};
	v = createVector(a4, sizeof(a4)/sizeof(a4[0]));
	cout << majorityElement(v) << endl;
	return 0;
}
