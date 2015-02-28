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
