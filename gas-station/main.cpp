#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int n = gas.size();
	if( n == 0 ) {
		return -1;
	}
	
	int start(0);
	int tank(0);
	int total(0);

	for(int i = 0; i < n; i++) {
		if((tank = tank+gas[i]-cost[i]) < 0) {
			total += tank;
			tank = 0;
			start = i+1;
		}	
	} 

	return total + tank < 0 ? -1 : start;
}

int main(int argc, char *argv[]) {
	vector<int> gas = {2,1,15,3,2};
	vector<int> cost = {4,1,9,3,2};
	cout << canCompleteCircuit(gas, cost) << endl;
	return 0;
}
