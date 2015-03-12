/*
	https://leetcode.com/problems/3sum-closest/
	{
		Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. 
		You may assume that each input would have exactly one solution.

		    For example, given array S = {-1 2 1 -4}, and target = 1.

		    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
	}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
	int n = num.size();
	int ans = 0;
	if(n <= 3) {
		for(int i = 0; i < n; i++) {
			ans += num[i];	
		}
		return ans;
	}

	sort(num.begin(), num.end());
	ans = num[0]+num[1]+num[2];
	for(int i = 0; i < n-2; i++) {
		int j = i+1;
		int k = n-1;
		while(j < k) {
			int sum = num[i] + num[j] + num[k];	
			if(sum == target) {
				return sum;
			}
			if(abs(target-sum) < abs(target-ans)) {
				ans = sum;
			}

			sum > target ? k-- : j++;
		}
	}
	return ans;
}

vector<int> createVector(int a[], int n) {
	vector<int> v;
	for(int ai = 0; ai < n; ai++) {
		v.push_back(a[ai]);	
	}
	return v;
}

int main(int argc, char *argv[]) {
	int a[] = {-1,2,1,-4};
	vector<int> v = createVector(a, sizeof(a)/sizeof(int));
	cout << threeSumClosest(v, 1) << endl;	
	return 0;
}
