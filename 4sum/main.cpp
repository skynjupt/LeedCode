/*
	https://leetcode.com/problems/4sum/
	{
	Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
	Find all unique quadruplets in the array which gives the sum of target.

	Note:
	Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
	The solution set must not contain duplicate quadruplets.
	    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

	    A solution set is:
	    (-1,  0, 0, 1)
	    (-2, -1, 1, 2)
	    (-2,  0, 0, 2)
	}
*/


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

#if 0
vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int> > vv;
	int n = num.size();
	if(n < 4) {
		return vv;
	}	

	sort(begin(num), end(num));
	unordered_map<int, vector<pair<int, int>>> mp;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			mp[num[i]+num[j]].push_back(make_pair(i,j));
		}
	}	

	for(int i = 0; i < n-3; i++) {
		if(i>0 && num[i] == num[i-1]) continue;
		for(int j = i+1; j < n-2; j++) {
			if(j>i+1 && num[j] == num[j-1]) continue;	
			int res = target - num[i] - num[j];
			if(mp.count(res)) {
				for(auto it = mp[res].begin(); it != mp[res].end(); it++) {
					int k = (*it).first, l = (*it).second;
					if(k > j) {
						if(!vv.empty() && num[i] == vv.back()[0]
								&& num[j] == vv.back()[1]
								&& num[k] == vv.back()[2]
								&& num[l] == vv.back()[3]) {
							continue;
						}
						vector<int> v={num[i], num[j], num[k], num[l]};
						vv.push_back(v);
					}
				} // for
			} // if
		} // for
	} // for

	return vv;
}
#endif

#if 0
/*
 	Time Limit Exceeded !!
 */
vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int> > vv;
	int n = num.size();
	if(n < 4) {
		return vv;
	}	

	sort(begin(num), end(num));
	map<int, vector<pair<int, int>>> mp;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			mp[num[i]+num[j]].push_back(make_pair(i,j));
		}
	}	

	int low = (mp.begin())->first;
	int high = (mp.rbegin())->first;	
	map<int, vector<pair<int, int>>>::iterator it;

	while(low <= high) {
		if(low + high > target) {
			if((it = --mp.lower_bound(high)) == mp.end())
				break;
			high = it->first;
		} else if(low + high  < target) {
			if((it = mp.upper_bound(low)) == mp.end())
				break;
			low = it->first;
		} else {
			int pi = INT_MAX, pj = INT_MAX; 
			for( auto it = mp[low].begin(); it != mp[low].end(); it++) {
				int i = it->first, j = it->second;	
				if(num[i] == pi && num[j] == pj) continue;	
				pi = num[i];
				pj = num[j];
				int pk = INT_MAX, pl = INT_MAX;
				for(auto jt = mp[high].begin(); jt != mp[high].end(); jt++) {
					int k = jt->first, l = jt->second;
					if(j < k) {	
						if(num[k] == pk && num[l] == pl) continue;	
						pk = num[k];
						pl = num[l];
						vector<int> v = {pi, pj, pk, pl};
						vv.push_back(v);
					}
				}
			}	
			
			if((it = --mp.lower_bound(high)) == mp.end())
				break;
			high = it->first;
	
			if((it = mp.upper_bound(low)) == mp.end())
				break;
			low = it->first;
		}
	}	

	return vv;
}
#endif

#if 1
vector<vector<int> > fourSum(vector<int> &num, int target) {
	vector<vector<int> > vv;
	int n = num.size();
	if(n < 4) {
		return vv;
	}	

	sort(begin(num), end(num));
	map<int, vector<pair<int, int>>> mp;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			mp[num[i]+num[j]].push_back(make_pair(i,j));
		}
	}	

	map<int, vector<pair<int, int>>>::iterator lowit = mp.begin();
	map<int, vector<pair<int, int>>>::reverse_iterator highit = mp.rbegin();

	while(lowit != mp.end() && highit != mp.rend() && lowit->first <= highit->first) {
		if(lowit->first + highit->first > target) {
			highit++;
		} else if(lowit->first + highit->first < target) {
			lowit++;
		} else {
			int pi = INT_MAX, pj = INT_MAX; 
			for( auto it = lowit->second.begin(); it != lowit->second.end(); it++) {
				int i = it->first, j = it->second;	
				if(num[i] == pi && num[j] == pj) continue;	
				pi = num[i];
				pj = num[j];
				int pk = INT_MAX, pl = INT_MAX;
				for(auto jt = highit->second.begin(); jt != highit->second.end(); jt++) {
					int k = jt->first, l = jt->second;
					if(j < k) {	
						if(num[k] == pk && num[l] == pl) continue;	
						pk = num[k];
						pl = num[l];
						vector<int> v = {pi, pj, pk, pl};
						vv.push_back(v);
					}
				}
			}	
			lowit++;	
			highit++;
		}
	}	

	return vv;
}
#endif

vector<int> createVector(int a[], int n) {
	vector<int> v;
	for(int ai = 0; ai < n; ai++) {
		v.push_back(a[ai]);	
	}
	return v;
}

void printVector(vector<vector<int> > &vv) {
	for(int i = 0; i < vv.size(); i++) {
		for(int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ",";
		}
		cout << endl;
	}
}


int main(int argc, char *argv[]) {
	//int a[] = {1,0,-1,0,-2,2};
//	int a[] = {-3,-1,0,2,4,5};
	int a[] = {-5,0,3,2,4};
	vector<int> num = createVector(a, sizeof(a)/sizeof(int));
//	vector<vector<int> > vv = fourSum(num, 0);
	vector<vector<int> > vv = fourSum(num, -14);
	printVector(vv);
	return 0;
}
