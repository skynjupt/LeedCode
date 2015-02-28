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
