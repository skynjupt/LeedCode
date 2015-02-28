#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}	
};

vector<Interval> merge(vector<Interval> &intervals) {
	sort(begin(intervals), end(intervals), 
		[] (const Interval &a, const Interval &b) {
			if(a.start != b.start) {
				return a.start < b.start;
			}	

			return a.end < b.end;
		});
	vector<Interval> rets;
	int n = intervals.size();
	for(int i = 0; i < n; i++) {
		int start = intervals[i].start;
		int end = intervals[i].end;
		while(i+1 < n && end >= intervals[i+1].start) {
			i++;
			end = intervals[i].end > end ? intervals[i].end : end;
		}

		rets.push_back(Interval(start, end));
	}

	return rets;
}

vector<Interval> createIntervals(int s[], int e[], int n) {
	vector<Interval> v;
	for(int i = 0; i < n; i++) {
		v.push_back(Interval(s[i], e[i]));	
	}
	return v;
}

void printIntervals(vector<Interval> &intervals) {
	for(auto i:intervals) {
		cout << "[" << i.start << "," << i.end << "] ";
	}
	cout << endl;
}


int main(int argc, char *argv[]) {
	int a[] = {2,0, 3,4 ,0,1, 8, 8, 8, 8, 8,15, 6, 12, 13, 14};
	int b[] = {6,0,3, 5, 4,6,12, 10, 11, 10,8, 18, 8, 13, 13, 14};

	vector<Interval> v = createIntervals(a, b, sizeof(a)/sizeof(a[0]));
	printIntervals(v);
	vector<Interval> t = merge(v);
	printIntervals(t);

	return 0;
}
