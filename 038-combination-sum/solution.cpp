/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb  7 15:01:52 2014
 * Modified at:   Sat Feb  8 21:22:07 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:

#ifdef SLOW_RECURSIVE
    void combinationSumRecursive(vector<int> &candidates, 
                                 int target,
                                 vector<vector<int> > &results,
                                 vector<int> &prev,
                                 int index) {

        if (0 == target && !prev.empty()) {
            results.push_back(prev);
        }

        for (int i = index; i < candidates.size(); ++i) {

            prev.push_back(candidates[i]);

            if (target >= 0) {
                combinationSumRecursive(candidates,
                                        target - candidates[i],
                                        results,
                                        prev,
                                        i
                    );
            }

            prev.pop_back();            
        }

    }



#endif  // SLOW_RECURSIVE 

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<int> > results;
        vector<int> previous;
        if (candidates.empty()) return results;

        // sort
        sort(candidates.begin(), candidates.end());
        
        combinationSumRecursive(candidates, target, 
                                results, previous, 0);

        // unique

        return results;
       
    }
};


int main() {

    Solution s;

    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(3);
    // candidates.push_back(6);
    // candidates.push_back(7);

    int target = 0;
    
    vector<vector<int> > results = s.combinationSum(candidates, target);

    for (int i = 0; i < results.size(); ++i) {
        cout << "[";
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
