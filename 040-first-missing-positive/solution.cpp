/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Feb  8 22:21:55 2014
 * Modified at:   Sat Feb  8 23:03:23 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        
        if (0 == n) return 1;
        
        // gen a hash table
        int *ht;
        ht = (int*)calloc(n, sizeof(int));
        
        for (int i = 0; i < n; ++i) ht[i] = 1;

        for (int i = 0; i < n; ++i) {

            if (A[i] > 0 && A[i] <= n) ht[A[i] - 1] = 0;

        }

        // see the smallest 1
        int idx = 0;
        while(ht[idx] != 1 && idx < n) {
            idx++;
        }

        return idx + 1;
        
    }
};

int main() {

    Solution s;

    int A[4] = {3, 4, -1, 1};

    int n = 4;

    int result = s.firstMissingPositive(A, n);

    cout << "The result is: " << result << endl;

    return 0;
}
