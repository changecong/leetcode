/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Feb  7 11:10:17 2014
 * Modified at:   Fri Feb  7 11:31:31 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
  
#ifdef BRUTE_FORCE

        if (0 == n) return 0;

        int i = 0;
        while (i < n) {

            if (A[i] >= target) break;

            i++;
           
        }
        return i;
            

#endif  // BRUTE_FORCE

#ifdef BIN_SEARCH

        if (0 == n) return 0;

        int result = 0;
        int mid = n / 2;

        int middle = A[mid];

        if (target == middle) {
            return mid;
        } else if (target > middle) {
            return (1 == n) ? mid + 1 : searchInsert(A + mid, n - mid, target) + mid;
        } else {
            return searchInsert(A, mid, target);
        }
        

#endif  // BIN_SEARCH
      
    }
};


int main() {

    Solution s;

    int A[6] = {0, 1, 2, 4, 5, 6};
    int n = 6;
    int target = 4;

    int result = s.searchInsert(A, n, target);

    cout << "The result is: " << result << endl;

    return 0;
}
