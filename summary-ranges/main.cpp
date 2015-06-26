/*
	https://leetcode.com/problems/summary-ranges/
	{
		Given a sorted integer array without duplicates, return the summary of its ranges.
		For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
	}
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> ret;
	string t;
	char st[32];
	int low = 0, high = 0;
	int size = nums.size();
	if(size <= 0) {
		return ret;
	} 

	for(int high = 1; high <= size; high++) {
		if(high < size && nums[high] == nums[high-1]+1) {
			continue;
		} else if(nums[high-1] == nums[low] ) {
			sprintf(st, "%d", nums[low]);
			t+=st;
		} else {
			sprintf(st, "%d", nums[low]);
			t+=st;
			if(low != high-1) {
				t+="->";
				sprintf(st, "%d", nums[high-1]);
				t+=st;
			}
			
		}
		ret.push_back(t);	
		t="";
		low=high;	
	} 

	return ret;
        
}

vector<int> createVector(int a[], int n) {
	vector<int> ret;
	for(int i = 0; i < n; i++) {
		ret.push_back(a[i]);	
	}
	return ret;
}

void myprint(vector<string> &s) {
	for(int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}

	cout << "-------------------------" << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {0, 1, 2, 4, 5, 7};	
	vector<int> nums = createVector(a, sizeof(a)/sizeof(a[0]));
	vector<string> ret = summaryRanges(nums);
	myprint(ret);
	
	return 0;
}
