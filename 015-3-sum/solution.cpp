/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 15 21:26:20 2014
 * Modified at:   Fri Jan 17 12:18:17 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "timer.hpp"

using namespace std;

#define TARGET 0
#define USING 1
#define UNUSED 0

class Solution {

public:
    vector<vector<int> > threeSum(vector<int> &num) {

#ifdef BRUTE_FORCE

        // time compleity would be O(n^3),
        // so we don't even consider it.

#endif  // BRUTE_FORCE

#ifdef SORT

TIME_INIT
TIME_START
        vector<vector<int> > results;
        // avoid empty
        if (3 > num.size()) return results;
            
        // sort  O(nlogn)
        sort(num.begin(), num.end());
        vector<int> result;
        

        for (int i = 0; i < num.size() - 2; ++i) {

            // skip i
            if (num[i] > 0) break;
            // if the same to previous one, move forward
            if (0 != i && num[i] == num[i-1]) continue;

            int head = i + 1;
            int tail = num.size() - 1;

            if (num[tail] < 0) break;

            int target = TARGET - num[i];

            while (head < tail) {
                // get it
                int diff = target - num[head] - num[tail];
                if ( diff == 0 ) {

                    result.clear();
                    result.push_back(num[i]);
                    result.push_back(num[head]);
                    result.push_back(num[tail]);
                    
                    results.push_back(result);

                    // skip
                    while (num[head] == num[head+1]) head++;
                    head++;
                    // skip 
                    while (num[tail] == num[tail-1]) tail--;
                    tail--;
                } else if (diff > 0) {
                    // skip
                    while (num[head] == num[head+1]) head++;
                    head++;
                } else {
                    // skip 
                    while (num[tail] == num[tail-1]) tail--;
                    tail--;
                }
                
            }

        }
TIME_END
        cout << "time: " << TIME_DURATION << endl;

        return results;
#endif  // SORT
    }
};


int main() {

    Solution s;
    
    // int a[6] = {-1, 0, 1, 2, -1, -4};
    int a[109] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};


    vector<int> num;
    vector<int> numnull;
    vector<int> num0;
    num0.push_back(0);

    for (int i = 0; i < 109; ++i) {
        num.push_back(a[i]);
    }

    vector<vector<int> > results = s.threeSum(num);

    // vector<vector<int> >::iterator it = results.begin();
    // while (it != results.end()) {
    //     cout << "< " ;
    //     for (int i = 0; i < 3; ++i) {
    //         cout << (*it)[i] << " " ;
    //     }
    //     cout << ">" << endl;

    //     it++;
    // }

    return 0;
}
