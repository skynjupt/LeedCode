/*
	https://leetcode.com/problems/candy/
	{
		There are N children standing in a line. Each child is assigned a rating value.

		You are giving candies to these children subjected to the following requirements:

		Each child must have at least one candy.
		Children with a higher rating get more candies than their neighbors.
		What is the minimum candies you must give?
	}
*/


#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings) {
	int n = ratings.size();
	if(n == 0) {
		return 0;
	}
	int preCandy = 1; //mean (i-1)'th candy when cal i'th
	int totalCandy = 1; // mean the minimun candies
	int lastIndex = 0; // mean the index of pre laster value which > cur value 
	int lastCandy = 1; // the lastIndex's candy

	for(int i = 1; i < n; i++) {
		if(ratings[i] > ratings[i-1]) { // mean: cur min candy is preCandy+1
			preCandy++;
			lastIndex = i;
			lastCandy = preCandy; 
		} else if(ratings[i] < ratings[i-1]) {
			if(preCandy == 1) { 
				if(i-lastIndex >= lastCandy) { // need +1 include lastindex ~ i-1
					totalCandy += (i-lastIndex); 
				} else {
					totalCandy += (i-lastIndex-1); // +1 include lastindex+1, i-1
				}
			}
			preCandy = 1;
		} else { // mean: curCandy set 1, and update lastIndex and lastCandy
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
