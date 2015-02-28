#include <iostream>
#include <vector>

using namespace std;

#if 0
int findPeakElement(const vector<int> &num) {
	int size = num.size();
	if(size == 0)
		return -1;
	if(size == 1) {
		return 0;
	}
	if(size >= 2 && num[0] > num[1]) {
		return 0;
	}
	
	int i = 1;
	for(i = 1; i < size-1; i++) {
		if(num[i-1] < num[i] && num[i] > num[i+1]) {
			return i;
		}
	}
	if(i == size-1 && num[i] > num[i-1]) {
		return i;	
	}
	
	return -1;
}
#endif

#if 0
int solve(const vector<int> &num, int low, int high) {
	if(low == high) {
		return low;
	}	

	int mid = (low+high)/2;
	if(num[mid]<num[mid+1]) {
		solve(num, mid+1, high);
	} else {
		solve(num, low, mid);
	}

}

int findPeakElement(const vector<int> &num) {
	return solve(num, 0, num.size()-1);	
}
#endif

#if 0
int findPeakElement(const vector<int> &num) {
	int low = 0;
	int high = num.size()-1;	
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

int findPeakElement(const vector<int> &num) {
	for(int i = 1; i < num.size(); i++) {
		if(num[i] < num[i-1]) {
			return i-1;
		}
	}	
	return num.size()-1;
}

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
