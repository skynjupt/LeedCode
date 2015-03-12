/*
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
	{
		Say you have an array for which the ith element is the price of a given stock on day i.

		Design an algorithm to find the maximum profit. You may complete at most k transactions.

		Note:
		You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
	}
*/
#include <iostream>
#include <vector>

using namespace std;

/*
 * P[k][i] = max{ P[k][i-1], P[k-1][j]+prices[i]-prices[j] (0<= j < i)} // k: at most i's transaction
 * ==>    P[k][i] = max{ P[k][i-1], prices[i] + (P[k-1][j]-prices[j]) (0<= j < i)} // k: the i's transaction
 * P[0][i] = 0
 * P[k][0] = 0
 */
int maxProfit(int k, vector<int> &prices) {
    	int n = prices.size();
	if(n == 0) {
		return 0;
	}
	// grady ,if not use grady, result in TLE;
	if(k >= n/2) {
		int maxTotalProfit = 0;
		for(int i=0; i < n-1; i++) {
			if(prices[i+1] > prices[i]) {
				maxTotalProfit += (prices[i+1]-prices[i]);
			}
		}
		return maxTotalProfit;
	}

	// dp
	vector<vector<int> > P(2, vector<int>(n, 0));
	int tmpMax = 0;

	for(int kk = 1; kk <= k; kk++) {
		int t = kk%2;
		tmpMax = P[(kk-1)%2][0] - prices[0];
		for(int ii = 1; ii < n; ii++) {
			P[t][ii] = max(P[t][ii-1], tmpMax+prices[ii]);	
			tmpMax = max(tmpMax, P[(kk-1)%2][ii]-prices[ii]);
		}
	}

	return P[k%2][n-1];        
}

int main(int argc, char *argv[]) {
	vector<int> prices = {32,12,24,3,6,22,14,16,12,18,3,2,9,3};
	cout << maxProfit(2,prices) << endl;
	prices = {2,5,4,6};
	cout << maxProfit(3, prices) << endl;
	return 0;
}
