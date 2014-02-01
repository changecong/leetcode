/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 21:49:32 2014
 * Modified at:   Fri Jan 31 22:05:42 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
  
        int result = 0;

        for (int i = 0; i < n; ++i) {
            // move from the tail to blank
            // then re-check the new element
            if (A[i] == elem) A[i--] = A[(n--)-1];
        }

        return n;
    }
};

int main() {
    
    Solution s;

    int a[10] = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1};

    int len = 10;

    int elem = 1;

    int result = s.removeElement(a, len, elem);

    cout << "the new length is : " << result << endl;

    return 0;
}

