/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Feb 10 14:33:55 2014
 * Modified at:   Mon Feb 10 21:32:15 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

using namespace std;

class Solution {

private:

#ifdef SLOW  // failed when the test size is 24
    int jumpRecursive(int A[], int head, int tail) {


        // get the minimum steps from head to tail
        int gap = tail - head;
        if (A[head] >= gap) return 1;

        int min = gap;

        // can not done by only one step
        // split
        for (int i = tail - 1; i > head; --i) {
            if (A[i] <= 0) continue;
            int sum = 0;
            if (A[i] == 1) {
                sum = jumpRecursive(A, head, i) + 1 + jumpRecursive(A, i + 1, tail);
            } else {
                sum = jumpRecursive(A, head, i) + jumpRecursive(A, i, tail);
            }
            if (sum == 2) return sum;
            if (min > sum) min = sum;
        }

        // cout << "[" << head << ", " << tail << "] : " << min << endl;
        return min;
    }
#endif  // SLOW
    
#ifdef FAST  // failed when test lenght is 94
    int jumpRecursive(int A[], int head, int tail, int prev) {

        // get the minimum steps from head to tail
        int gap = tail - head;
        if (A[head] >= gap) return 1;
        
        int min = gap;
 
        // can not done by only one step
        // split
        for (int i = prev + 1; i <= head + A[head]; ++i) {
            if (A[i] <= 0) continue;

            int sum = 1 + jumpRecursive(A, i, tail, head + A[head]);
            
            if (sum == 2) return sum;
            if (min > sum) min = sum;
        }

        // cout << "[" << head << ", " << tail << "] : " << min << endl;
        return min;

    }

#endif  // FAST



public:
    int jump(int A[], int n) {
  
        if (A[0] == 0) return 0;

        if (n < 2) return 0;

        if (n == 2) return 1;

#ifdef FASTEST

        int step = 0;
        int longest = 0;
        int prev = 0;

        for (int i = 0; i < n; ++i) {

            if (i > prev) {

                prev = longest;
                step++;
            }

            longest = (longest > (A[i] + i)) ? longest : (A[i] + i);
        }

        return step;


#endif  // FASTEST
        
#ifdef SLOW
        return jumpRecursive(A, 0, n-1);
#endif  // SLOW

#ifdef FAST
        return jumpRecursive(A, 0, n-1, 0);
#endif  // FAST

    }
};

int main() {

    Solution s;

    // int A[3] = {1, 2, 3};
    // int A[6] = {2, 3, 1, 1, 1, 4};
    // int A[20] = {9, 8, 2, 1, 0, 2, 2, 0, 4, 1, 5, 7, 9, 6, 6, 0, 6, 5, 0, 5};
    // int A[24] = {6, 2, 6, 1, 7, 9, 3, 5, 3, 7, 2, 8, 9, 4, 7, 7, 2, 2, 8, 4, 6, 6, 1, 3};
    // int A[26] = {2, 9, 6, 5, 7, 0, 7, 2, 7, 9, 3, 2, 2, 5, 7, 8, 1, 6, 6, 6, 3, 5, 2, 2, 6, 3};
    // int A[39] = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    // int A[84] = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    int A[95] = {5,8,1,8,9,8,7,1,7,5,8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0};
    int n = 95;

    int result = s.jump(A, n);
    
    cout << "The minimum number of jumps is: " << result << endl;

    return 0;
}
