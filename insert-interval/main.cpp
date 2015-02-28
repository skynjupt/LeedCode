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

bool cmp(const Interval &a, const Interval &b) {
	if(a.start != b.start) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> v(intervals);
	v.push_back(newInterval);
	sort(v.begin(), v.end(), cmp);
	
	int n = v.size();
	vector<Interval> rets;
	for(int i = 0; i < n; i++) {
		int start = v[i].start;
		int end = v[i].end;
		while(i+1 < n && end >= v[i+1].start) {
			i++;
			end = v[i].end > end ? v[i].end : end;
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
	for(int i = 0; i < intervals.size(); i++) {
		cout << "[" << intervals[i].start << "," << intervals[i].end << "],";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int s[] = {1,3,6,8,12};
	int e[] = {2,5,7,10,16};
	vector<Interval> v = createIntervals(s,e,sizeof(s)/sizeof(s[0]));
	printIntervals(v);
	Interval newInterval(4,9);
	v = insert(v, newInterval);
	printIntervals(v);
	return 0;
}
