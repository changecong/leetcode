/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sun Mar 16 18:49:36 2014
 * Modified at:   Sun Mar 16 19:03:02 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {

        if (0 == m) {  // A is empty

            // move B into A
            for (int i = 0; i < n; ++i) {
                A[i] = B[i];
            }

        } else if (0 != n) {  // B

            int len = m + n;

            int idx_a = m - 1;
            int idx_b = n - 1;
            int idx = len - 1;

            while (idx_a >= 0 && idx_b >= 0) {

                if (A[idx_a] >= B[idx_b]) {
                    
                    A[idx] = A[idx_a];
                
                    idx_a--;
                } else {
                    A[idx] = B[idx_b];
                    idx_b--;
                }
                
                idx--;
            }

            if (idx_a < 0) {  // A is over
                merge(A, 0, B, idx_b + 1);
            }
            
            // if B is empty() the rest of A are already in A
        }
        
    }
};


int main() {

    Solution s;

    int A[10] = {1, 3, 5, 7, 9};
    int B[5] = {2, 4, 6, 8, 10};

    int m = 5;
    int n = 5;

    s.merge(A, m, B, n);

    for (int i = 0; i < m + n; ++i) {

        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}

