/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Feb 13 13:00:03 2014
 * Modified at:   Thu Feb 13 19:59:08 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
  
        if (n == 0) return false;
        if (n == 1) return true;
        if (A[0] == 0) return false;

        bool result = true;

        for(int i = 0; i < n - 1; ++i) {

            // iff there is at least on A[i] which is 0
            // it might be false
            if (A[i] == 0) {
                
                int temp = i - 1;

                while(temp >= 0) {
                    int dist = i - temp;
                    if (A[temp] > dist) {  // could skip 0
                        break;
                    } else {
                        temp--;  // move left until the 0 can be skipped
                    }
                }
                
                if (temp < 0) return false;

            }
            
        }
        
        return true;
    }
};

int main() {
    
    Solution s;

    int A[5] = {3, 2, 1, 1, 4};
    int n = 5;

    bool result = s.canJump(A, 5);

    cout << "Can " << (result ? "" : "not ") << "jump to the last." << endl;

    return 0;
}
