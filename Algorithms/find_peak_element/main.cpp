/*
	https://leetcode.com/problems/find-peak-element/
	{
		A peak element is an element that is greater than its neighbors.

		Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

		The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

		You may imagine that num[-1] = num[n] = -¡Þ.

		For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

		Note:
		Your solution should be in logarithmic complexity.
	}
*/
#include <iostream>
#include <vector>

using namespace std;

#if 1
int findPeakElement(const vector<int> &num) {
	int low = 0;
	int high = num.size()-1;
	// binary search, for each iteration, make sure num[low-1]< num[low] & num[high] > num[high+1] is true  
	while(low < high) {	
		int mid = (low+high)/2;
		if(num[mid] < num[mid+1])
			low = mid+1;	
		else
			high = mid;
	}	

	return low;	
}
#endif

#if 0
int findPeakElement(const vector<int> &num) {
	for(int i = 1; i < num.size(); i++) {
		if(num[i] < num[i-1]) {
			return i-1;
		}
	}	
	return num.size()-1;
}
#endif

int main(int argc, char *argv[])
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	cout << findPeakElement(a) << endl;
	
	vector<int> b;
	b.push_back(7);
	b.push_back(2);
	b.push_back(3);
	b.push_back(8);
	cout << findPeakElement(b) << endl;
	return 0;
}
