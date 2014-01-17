/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 17 12:23:11 2014
 * Modified at:   Fri Jan 17 13:12:04 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

#ifdef SORT

        int result = 0x7fffffff;

        if (3 > num.size()) return result;

        sort(num.begin(), num.end());
        
        int diff = 0x7fffffff;

        for (int i = 0; i < num.size() - 2; ++i) {
            
            // skip
            // if (i > target) break;
            // if (i != 0 && num[i] == num[i-1]) continue;
            
            // head and tail
            int head = i + 1;
            int tail = num.size() - 1;

            while (head < tail) {
                int sum = num[i] + num[head] + num[tail];
                int temp_diff = (target > sum) ? target - sum : sum - target;
                if (0 == temp_diff) {
                    return target;
                }

                if (temp_diff < diff) {
                    result = sum;
                    diff = temp_diff;
                }

                if (sum < target) head++;
                else tail--;
            }
            
        }

        return result;

#endif  // SORT
      
    }
};


int main() {

    Solution s;

    int target = -100;

    int a[4] = {1, 1, 1, 0};
    
    vector<int> num;
    for (int i = 0; i < 4; ++i) {
        num.push_back(a[i]);
    }

    int result = s.threeSumClosest(num, target);

    cout << "The target is: " << target << endl;
    cout << "The closest result is: " << result << endl;

    return 0;
}
