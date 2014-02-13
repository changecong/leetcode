/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Feb 12 16:42:05 2014
 * Modified at:   Thu Feb 13 11:33:10 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {

#ifdef ONE_POINTER

        int ptr = 0;

        int max = A[ptr];
        int sum = A[ptr];

        while(ptr < n - 1) {
            
            ptr++;

            if(sum <= 0) {  // move forward
                sum = A[ptr];
            } else {
                sum += A[ptr];
            }

            max = (sum > max) ? sum : max;

        }
        
        return max;
        
#endif  // ONE_POINTER

#ifdef DIVIDE_AND_CONQUER

        // TODO divide and conquer

#endif  // DIVIDE_AND_CONQUER

        
    }
};


int main() {

    Solution s;

    int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5};

    int n = 9;

    int result = s.maxSubArray(A, n);

    cout << "The result is: " << result << endl;

    return 0;
}
