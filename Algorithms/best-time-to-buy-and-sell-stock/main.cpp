/*
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
	{
		Say you have an array for which the ith element is the price of a given stock on day i.

		If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.	
	}
*/

#include <iostream>
#include <vector>

using namespace std;

// p[i] = MAX{A[i]-min, Pmax} 
// min : the min of A[0] ~ A[i-1], 
// Pmax: the max profit
int maxProfit(vector<int> &prices) {
	if(prices.empty())
		return 0;

	int min = 0;
	int maxProfit = 0;

	for(int i = 0, min = prices[0]; i < prices.size(); i++) {
#if 0
		if(prices[i] - min > maxProfit)
			maxProfit = prices[i] - min;
		if(prices[i] < min)
			min = prices[i];
#else 
		if(prices[i] < min)
			min = prices[i];
		else if(prices[i] - min > maxProfit)
			maxProfit = prices[i] - min;

#endif
	}
	return maxProfit;
}

int main(int argc, char *argv[])
{
#if 1
	vector<int> a(4);
	a[0] = 2;
	a[1] = 7;
	a[2] = 1;
	a[3] = 9;

	cout << maxProfit(a) << endl;
#endif
	
	return 0;
}
