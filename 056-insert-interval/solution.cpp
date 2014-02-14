/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 13 22:45:13 2014
 * Modified at:   Thu Feb 13 23:34:01 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {


        // insert then merge

        // insert 
        intervals.push_back(newInterval);

        if(intervals.size() < 2) return intervals;

        // sort
        sort(intervals.begin(), intervals.end(), compareInterval);

        vector<Interval> result;

        for (int i = 0; i < intervals.size(); ++i) {

            int j = i + 1;
            int max_end = intervals[i].end;
            
            while (max_end >= intervals[j].start && j < intervals.size()) {  // overlap

                max_end = (max_end > intervals[j].end) ? max_end : intervals[j].end;
                
                j++;
            }
            j--;

            if (i == j) {
                result.push_back(intervals[i]);
            } else {
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
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(12, 16));
    
    Interval newInterval(4, 9);

    vector<Interval> result = s.insert(intervals, newInterval);

    for (int i = 0; i < result.size(); ++i) {

        cout << "[" << result[i].start << ", " << result[i].end << "] ";
    }

    cout << endl;

    return 0;
}
