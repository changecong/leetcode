/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Feb  8 21:50:40 2014
 * Modified at:   Sat Feb  8 22:10:32 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

private:

    void combinationSum2Recursive(vector<int> &num,
                                  int target,
                                  vector<vector<int> > &results,
                                  vector<int> &prev,
                                  int index) {

        if (0 == target && !prev.empty()) {
            results.push_back(prev);
        }

        for (int i = index; i < num.size(); ++i) {

            // skip the duplication one
            if (i != index && num[i] == num[i - 1]) continue;

            prev.push_back(num[i]);

            if (target > 0) {
                combinationSum2Recursive(num, target - num[i],
                                         results,
                                         prev, 
                                         i + 1  // each candidates can only be used once
                    );
            }

            prev.pop_back();

        }
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        
        vector<vector<int> > results;
        if (num.empty()) return results;

        sort(num.begin(), num.end());

        if (target < num[0]) return results;

        vector<int> prev;

        combinationSum2Recursive(num, target,
                                 results, prev, 0);
        
        return results;
    }
};


int main() {

    Solution s;

    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    int target = 8;
    
    vector<vector<int> > results = s.combinationSum2(candidates, target);

    for (int i = 0; i < results.size(); ++i) {
        cout << "[";
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
