/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb  4 18:14:27 2014
 * Modified at:   Tue Feb  4 22:56:34 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        
#ifdef BRUTE_FORCE

        for (int i = 0; i < n; ++i) {
            
            if (A[i] == target) return i;

        }

        return -1;

#endif  // BRUTE_FORCE

#ifdef BIN_SEARCH

        if (0 == n) return -1;
        if (1 == n) return (A[0] == target) ? 0 : -1;
        if (2 == n) {
            if (A[0] == target) return 0;
            else if (A[1] == target) return 1;
            else return -1;
        }

        int mid = n / 2;

        int head = A[0];
        int tail = A[n - 1];

        if (A[mid] > head) {

            if (target >= head && target <= A[mid]) {
                return search(A, mid + 1, target);
            } else {
                int result = search(A + mid, n - mid, target);
                return (-1 == result) ? result : result + mid;
            }

        } else if (A[mid] <= head) {

            if (target >= A[mid] && target <= tail) {
                int result = search(A + mid, n - mid, target);
                return (-1 == result) ? result : result + mid;
            } else {
                return search(A, mid + 1, target);
            }
        }

#endif  // BIN_SEARCH


    }
};

int main() {

    Solution s;

    int n = 8;
    int A[8] = {2, 3, 4, 5, 6, 7, 0, 1};
    for (int target = 0; target < 9; target++) {

        int result = s.search(A, n, target);


        cout << "The result is: " << result <<endl;

    }

    return 0;
}
