//
// Created by sensetime on 4/15/17.
//
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval x, Interval y) {
    return x.start < y.start || (x.start == y.start && x.end < y.end);
}

vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    const int size = intervals.size();
    vector<Interval> result;
    sort(intervals.begin(), intervals.end(), comp);
    int currentBegin = intervals[0].start;
    int currentEnd = intervals[0].end;
    for (int i = 1; i < size; ++i) {
        if (currentEnd >= intervals[i].start) {
            if (currentEnd < intervals[i].end) {
                currentEnd = intervals[i].end;
            }
        } else {
            result.push_back(Interval(currentBegin, currentEnd));
            currentBegin = intervals[i].start;
            currentEnd = intervals[i].end;
        }
    }
    result.push_back(Interval(currentBegin, currentEnd));
    return result;
}

int main() {
    vector<Interval> intervals = {
            Interval(1, 4),
            Interval(0, 4)
    };
    vector<Interval> merged = merge(intervals);
    for (int i = 0; i < merged.size(); ++i) {
        cout << "[" << merged[i].start << "," << merged[i].end << "]";
        cout << endl;
    }
}