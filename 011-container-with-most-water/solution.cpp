/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Jan 15 12:27:53 2014
 * Modified at:   Wed Jan 15 13:28:42 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Brute force: the time complexity is O(n^2)
 *                             can not pass the leetcode time limit.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {

// #ifdef BRUTE_FORCE

private:

    int diff(int n, int m) {
        return (m > n) ? m - n : n - m;
    }

    int MIN(int n, int m) {
        return (m > n) ? n : m;
    }

    int MAX(int n, int m) {
        return (m > n) ? m : n;
    }

// #endif  // BRUTE_FORCE

public:
    int maxArea(vector<int> &height) {

#ifdef BRUTE_FORCE

        // v = min(an. am) * |(m - n)|;

        int v = 0;
        for (int n = 0; n < height.size(); ++n) {
            for (int m = n + 1; m < height.size(); ++m) {
                int temp_v = MIN(height[n], height[m]) * (m - n);
                v = MAX(v, temp_v);
            }
        }

        return v;
        

#endif  // BRUTE_FORCE

#ifdef LINEAR

        int n = 0;
        int m = height.size() - 1;
        int v = 0;

        while (n < m) {
            int temp_v = MIN(height[n], height[m]) * (m - n);
            v = MAX(v, temp_v);
            
            if (height[n] < height[m]) {
                n++;
            } else m--; 
        }

        return v;

#endif  // LINEAR
    }
};


int main() {

    Solution s;
    int a[5] = {1, 3, 4, 0, 2};
    vector<int> height;
    for (int i = 0; i < 5; ++i) {
        height.push_back(a[i]);
    }

    int max = s.maxArea(height);

    cout << "the max area is : " << max << endl;

    return 0;
}
