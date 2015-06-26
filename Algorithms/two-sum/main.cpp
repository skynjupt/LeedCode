/*
https://leetcode.com/problems/two-sum/
{
Given an array of integers, find two numbers 
such that they add up to a specific target number.

The function twoSum should return indices of the two numbers
such that they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) 
are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
}
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#if 0
//#define hash(v, M) (v % M)

static int M;
static vector<int> vt;

int inline hash(int v, int M) {
//	return v % M;
	return v * v % M;
}

void STinit(int max) {
	M = 2*max;
	vt.clear();
	for(int i = 0; i < M; i++) {
		vt.push_back(-1);	
	}
}

int STinsert(int val, int t) {
	int i = hash(val, M);
	while(vt[i] != -1) i = (i+1) % M;
	vt[i] = t;
}

int STsearch(int val, vector<int> &numbers) {
	int i = hash(val, M);
	while(vt[i] != -1) {
		if(numbers[vt[i]] == val) return vt[i];
		else i = (i+1) % M;
	}
	return -1;
}

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> v;
	int n = numbers.size();
	STinit(n);
	STinsert(numbers[0], 0);
	int t = 0;
	int low = -1;
	for(int i = 1; i < n; i++) {
		t = target - numbers[i];
		low = STsearch(t, numbers);
		if(low >= 0) {
			v.push_back(low+1);
			v.push_back(i+1);	
			break;
		} else {
			STinsert(numbers[i], i);	
		}
	}	
	return v;
}

#endif

vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int, int> hash;
	vector<int> result;
	for(int i = 0; i < numbers.size(); i++) {
		int numbersToFind = target - numbers[i];

		if(hash.find(numbersToFind) != hash.end()) {
			result.push_back(hash[numbersToFind] + 1);
			result.push_back(i + 1);
			break;	
		}

		hash[numbers[i]] = i;
	}	

	return result;
}

vector<int> createVector(int a[], int n) {
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.push_back(a[i]);	
	}
	return v;
}

void printVector(vector<int> &v) {
	if(v.size() == 0) {
		return;
	}

	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {2, 7, -2, 15};
	vector<int> v = createVector(a, sizeof(a)/sizeof(a[0]));
	vector<int> t = twoSum(v, 0);
	printVector(v);
	printVector(t);		
	int b[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,
		740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,
		61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,
		173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,
		737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,
		328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};

	v = createVector(b, sizeof(b)/sizeof(b[0]));
	t = twoSum(v, 542);
	printVector(v);
	printVector(t);		
	return 0;
}
