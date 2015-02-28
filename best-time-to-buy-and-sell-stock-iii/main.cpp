#include <iostream>
#include <vector>

using namespace std;

/*
 * P[k][i] = max{ P[k][i-1], P[k-1][j]+prices[i]-prices[j] (0<= j < i)} // k: at most i's transaction
 * ==>    P[k][i] = max{ P[k][i-1], prices[i] + (P[k-1][j]-prices[j]) (0<= j < i)} // k: the i's transaction
 * P[0][i] = 0
 * P[k][0] = 0
 */
int maxProfit(vector<int> &prices) {
	int n = prices.size();
	if(n == 0) {
		return 0;
	}
	int k = 2;
	vector<vector<int> > P(k+1, vector<int>(n, 0));
	int tmpMax = 0;

	for(int kk = 1; kk <= k; kk++) {
		tmpMax = P[kk-1][0] - prices[0];
		for(int ii = 1; ii < n; ii++) {
			P[kk][ii] = max(P[kk][ii-1], tmpMax+prices[ii]);	
			tmpMax = max(tmpMax, P[kk-1][ii]-prices[ii]);
		}
	}

	return P[k][n-1];
}

int main(int argc, char *argv[]) {
	vector<int> prices = {32,12,24,3,6,22,14,16,12,18,3,2,9,3};
	cout << maxProfit(prices) << endl;
	prices = {2,5,4,6};
	cout << maxProfit(prices) << endl;
	return 0;
}
