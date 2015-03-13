/*
	https://leetcode.com/problems/container-with-most-water/
	{
		Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
		n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
		which together with x-axis forms a container, such that the container contains the most water.

		Note: You may not slant the container.
	}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int maxArea(vector<int> &height) {
	int max = 0;
	int left = 0;
	int right = height.size() - 1;
	while(left < right) {
		int t = (right-left) * min(height[left], height[right]);
		if(t > max) max = t;
		height[left] < height[right] ? left++ : right--;
	}
	return max;
}

int main(int argc, char *argv[]) {
	vector<int> height = {2, 6, 7, 3};
	cout << maxArea(height) << endl;
	return 0;
}
