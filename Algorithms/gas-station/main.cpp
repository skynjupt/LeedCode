/*
	https://leetcode.com/problems/gas-station/
	{
		There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

		You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
		its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

		Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

		Note:
		The solution is guaranteed to be unique.
	}
*/

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
