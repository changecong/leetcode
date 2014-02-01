/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Jan 31 22:10:54 2014
 * Modified at:   Fri Jan 31 23:45:09 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
  
#ifdef BRUTE_FORCE

        // if n = 0;
        if (0 == n) return 0;
        if (1 == n) return 1;


        for (int i = 0; i < n; ++i) {

            int j = i + 1;
            if (j == n) return n;

            while (j < n && A[j] == A[i]) {
                j++;
                if(j == n) {
                    // last
                    return ++i;  // length
                }
            }

            int gap = j - i;

            while (j < n) {
                A[j - gap + 1] = A[j++];
            }

            n = n - gap + 1;
        }

        return n;

#endif  // BRUTE_FORCE

#ifdef TWO_POINTERS

        int i = 0;
        int j = i + 1;

        // if n = 0;
        if (0 == n) return 0;
        if (1 == n) return 1;

        for (;i < n; ++i) {

            while (j < n && A[j] == A[i]) {
                j++;
                if(j == n) {
                    // last
                    return ++i;  // length
                }
            }

            A[i+1] = A[j];
        }

        return ++i;

#endif  // TWO_POINTERS
      
    }
};

int main() {

    Solution s;

    int a[17] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 6};

    int len = 1;

    int result = s.removeDuplicates(a, len);

    cout << "The new length is: " << result << endl;

    return 0;
}
