#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
	int n = prices.size();
	int profit = 0;
	for(int i = 0; i < n-1; i++) {
		if(prices[i+1] > prices[i]) {
			profit += prices[i+1] - prices[i];
		}	
	} 	

	return profit;
}


int main(int argc, char *argv[]) {
	vector<int> prices = {2,3,4,5,3,7};
	cout << maxProfit(prices) << endl;
	return 0;
}
