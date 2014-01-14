/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Jan  6 20:49:56 2014
 * Modified at:   Mon Jan  6 23:35:04 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   Find median of two sorted arrays
 *                Merge: time = O(m+n)
 *
 */

#include <iostream>

class Solution {

#ifdef KTH
private:

    int min(int a, int b) {
        
        return a < b ? a : b;
    }

    double kth(int A[], int m, int B[], int n, int k) {

        // boundary conditions
        if (m > n) {
            return kth(B, n, A, m, k);
        }

        if (0 == m) {
            return B[k-1];
        }

        if (1 == k) {
            return min(A[0], B[0]);
        }

        // three possible conditions
        // assume m is less
        int k1 = min(k/2, m);
        int k2 = k - k1;
        if (A[k1 - 1] < B[k2 - 1]) {
            // kth is not in A[0, k1-1]
            return kth(A + k1, m - k1, B, n, k2);
        } else if (A[k1 - 1] > B[k2 - 1]) {
            // kth is not in B[0, k2 - 1]
            return kth(A, m, B + k2, n - k2, k1);
        } else {
            return A[k1 - 1];
        }
    }
#endif  // KTH

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {

#ifdef MERGE
        int a, b, c;
        a = b = c = 0;
        int temp = 0;
        int backward = 0;
        while(a <= m || b <= n) {
                backward = temp;
                if (m == 0 && n == 0) {
                    return 0.0;
                } else if (n == 0) {
                    temp = A[a];
                    a++;
                } else if (m == 0){
                    temp = B[b];
                    b++;   
                } else if (b == n) {
                    temp = A[a];
                    a++;    
                } else if (a == m) {
                    temp = B[b];
                    b++;     
                } else if (A[a] < B[b]) {
                    temp = A[a];
                    a++;
                } else if (A[a] >= B[b]){
                    temp = B[b];
                    b++;                    
                }
                
                if (c == (int)((m+n)/2)) {
                    // c points to either the left of median (odd)
                    // or the left element of the median
                    if ((m+n)%2 == 0) {
                        // even, right element
                        return (temp+backward)/2.0;
                    }

                    if ((m+n)%2 == 1) {
                        // odd
                        return (double)temp;
                    }
                }
                
                c++;           
        }
#endif  // MERGE

#ifdef KTH
        // assume the median is the kth smallest number
        int total = m + n;
        
        // is total is odd
        if (total & 0x1) {  // last digit is 1
            return kth(A, m, B, n, total/2 + 1);
        } else {  // last digit is 0
            return (kth(A, m, B, n, total/2) + kth(A, m, B, n, total/2 + 1)) / 2.0;
        }

#endif  // KTH
    }
};


int main() {

    Solution s;

    int m = 2;
    int n = 2;
    int A[2] = {1, 2};
    int B[2] = {1, 2};
    
    double result = s.findMedianSortedArrays(A, m, B, n);
    
    std::cout << "median: " << result << std::endl;

    return 0;
}
