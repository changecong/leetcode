/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 13 13:18:08 2014
 * Modified at:   Thu Mar 13 21:37:53 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
  
#ifdef LOOKUP_TABLE

#endif  // LOOKUP_TABLE

#ifdef BINARY_SEARCH

        

        if (0 == n) return false;
        // cout << A[0] << endl;
        if (1 == n) return (A[0] == target) ? true : false;

        int mid = n / 2;
       
        return search(A, mid, target) || search(A + mid, n - mid, target);


#endif  // BINARY_SEARCH

#ifdef ADVANCED

        if (0 == n) return false;
        
        if (1 == n) return (A[0] == target) ? true : false;
        if (2 == n) return (A[0] == target || A[1] == target) ? true : false;

        int mid = (n / 2);
        int middle = A[mid];
        int head = A[0];
        int tail = A[n - 1];

        if (middle > head) {

            if (target >= head && target <= middle) {
                return search(A, mid + 1, target);
            } else {
                return search(A + mid, n - mid, target);
            }
        } else if (middle < head) {

            if (target >= middle && target <= tail) {
                return search(A + mid, n - mid, target);
            } else {
                return search(A, mid + 1, target);
            }
            
        } else if (middle == head) {
            
            return search(A, mid + 1, target) || search(A + mid, n - mid, target);;
        }
        

#endif  // ADVAMCED
      
      
    }
};


int main() {

    Solution s;

    int A[4] = {1, 3, 1, 1};
    int n = 4;
    
    int target = 3;

    bool result = s.search(A, n, target);

    cout << (result ? "find" : "not find") << endl;

    return 0;
}
