#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings) {
	int n = ratings.size();
	if(n == 0) {
		return 0;
	}
	int preCandy = 1;
	int totalCandy = 1;
	int lastIndex = 0;
	int lastCandy = 1;

	for(int i = 1; i < n; i++) {
		if(ratings[i] > ratings[i-1]) {
			preCandy++;
			lastIndex = i;
			lastCandy = preCandy; 
		} else if(ratings[i] < ratings[i-1]) {
			if(preCandy == 1) {
				if(i-lastIndex >= lastCandy) {
					totalCandy += (i-lastIndex);
				} else {
					totalCandy += (i-lastIndex-1);
				}
			}
			preCandy = 1;
		} else {
			preCandy = 1;
			lastIndex = i;
			lastCandy = preCandy;
		}
		totalCandy += preCandy;
	}

	return totalCandy;
}

int main(int argc, char *argv[]) {
	vector<int> ratings = {1,2,2}; // min 4
	cout << candy(ratings) << endl;
	ratings = {2,2,1}; // min 4
	cout << candy(ratings) << endl;
	ratings = {2,3,2}; // min 4
	cout << candy(ratings) << endl;
	ratings = {5,3,1}; // min 6
	cout << candy(ratings) << endl;
	ratings = {1,2,4,4,3}; // min 9
	cout << candy(ratings) << endl;
	ratings = {1,3,4,3,2,1}; // min 13 
	cout << candy(ratings) << endl;
	return 0;
}
