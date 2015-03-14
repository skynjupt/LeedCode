/*
	https://leetcode.com/problems/pascals-triangle/
	{
Pascal's Triangle I
		Given numRows, generate the first numRows of Pascal's triangle.

		For example, given numRows = 5,
		Return

		[
		     [1],
		    [1,1],
		   [1,2,1],
		  [1,3,3,1],
		 [1,4,6,4,1]
		]

Pascal's Triangle II 
	Given an index k, return the kth row of the Pascal's triangle.

	For example, given k = 3,
	Return [1,3,3,1].
	
	}
*/



#include <iostream>
#include <vector>

using namespace std;
// 1
//1 1
//1 2 1
//1 3 3 1
// 1 4 6 4 1

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > vv;
	vector<int> v;
	
	for(int i=0; i<numRows; i++) {
		v.clear();
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i) {
				v.push_back(1);
			} else if(i>0 && j > 0) {
				v.push_back(vv[i-1][j-1]+vv[i-1][j]);
			}
		}
		vv.push_back(v);
	}	

	return vv;	
}

vector<int> getRow(int rowIndex) {
	vector<int> v;
	for(int i=0; i <= rowIndex; i++) {
		for(int j = i; j >= 0; j--) {
			if(j == i) {
				v.push_back(1);
			} else if(j > 0) {
				v[j] += v[j-1];
			}	
		}
	}	
	return v;
}

void printTest(vector<vector<int> >& vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++)
			cout << vv[i][j] << " ";
		cout << endl;
	}
}

void printTest1(vector<int>& v) {
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[])
{
#if 0
	cout << "1:" << endl;
	vector<vector<int> > a = generate(1);
	printTest(a);
	cout << "5:" << endl;
	vector<vector<int> > a1 = generate(5);
	printTest(a1);
#endif
	
	cout << "1:" << endl;
	vector<int> a = getRow(1);
	printTest1(a);
	cout << "5:" << endl;
	vector<int> a1 = getRow(3);
	printTest1(a1);
	return 0;
}
