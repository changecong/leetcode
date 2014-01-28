/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 17 13:15:31 2014
 * Modified at:   Tue Jan 28 15:16:16 2014
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
    vector<vector<int> > fourSum(vector<int> &num, int target) {

#ifdef SUM3

        // time complexity O(n^3)

        vector<vector<int> > results;
        int len = num.size();
        if (4 > len) return results;        

        // sort
        sort(num.begin(), num.end());

        for (int i = 0; i < len - 3; ++i) {

            // skip
            // if (num[i] > target) break;
            if (0 != i && num[i] == num[i-1]) continue;

            int target0 = target - num[i];

            // 3 sum
            for (int j = i + 1; j < len - 2; ++j) {
                
                // skip
                // if (num[j] > target0) break;
                if ((i + 1) != j && num[j] == num[j-1]) continue;

                int target1 = target0 - num[j];

                int head = j + 1;
                int tail = len - 1;

                // if(num[tail] < target0) continue;
                
                while(head < tail) {
                    
                    int diff = target1 - num[head] - num[tail];

                    if (0 == diff) {
                        vector<int> result;
                        result.push_back(num[i]);
                        result.push_back(num[j]);
                        result.push_back(num[head]);
                        result.push_back(num[tail]);

                        results.push_back(result);
                        // skip
                        while(num[head] == num[head+1]) head++;
                        head++;
                        while(num[tail] == num[tail-1]) tail--;
                        tail--;
                    } else if (0 < diff) {
                        // skip
                        while(num[head] == num[head+1]) head++;
                        head++;
                    } else {
                        while(num[tail] == num[tail-1]) tail--;
                        tail--;
                    }
                    
                }
                
            }
            

        }

        return results;

#endif  // SUM3  
      
    }
};

int main() {

    Solution s;
    
    int a[8] = {1,-2,-5,-4,-3,3,3,5};
    // int a[4] = {2, 1, 0, -1};
    // int a[109] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

    int target = -11;

    vector<int> num;
    vector<int> numnull;
    vector<int> num0;
    num0.push_back(0);

    for (int i = 0; i < 8; ++i) {
        num.push_back(a[i]);
    }

    vector<vector<int> > results = s.fourSum(num, target);

    vector<vector<int> >::iterator it = results.begin();
    while (it != results.end()) {
        cout << "< " ;
        for (int i = 0; i < 4; ++i) {
            cout << (*it)[i] << " " ;
        }
        cout << ">" << endl;

        it++;
    }

    return 0;
}
