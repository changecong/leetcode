/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if (intervals.size() < 2) return intervals;

        vector<Interval> result;

        // sort
        sort(intervals.begin(), intervals.end(), compareInterval);

        for (int i = 0; i < intervals.size(); ++i) {

            int j = i + 1;
            int max_end = intervals[i].end;
            
            while (max_end >= intervals[j].start && j < intervals.size()) {  // overlapping
                
                // store the max end;
                max_end = (max_end > intervals[j].end) ? max_end : intervals[j].end;
                j++;
            }
            
            j--;
            if (j == i) {
                result.push_back(intervals[i]);
            } else {
                // merge
                Interval temp(intervals[i].start, max_end);
                result.push_back(temp);
            }

            i = j;     
            
        }

        return result;
    }
};


int main() {

    Solution s;

    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    intervals.push_back(Interval(2, 6));

    vector<Interval> result = s.merge(intervals);

    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i].start << ", " << result[i].end << "] ";
    }
    cout << endl;

    return 0;
}
