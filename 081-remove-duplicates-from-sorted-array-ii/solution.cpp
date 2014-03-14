/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 13 21:44:11 2014
 * Modified at:   Thu Mar 13 22:02:28 2014
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

        // in place
        if (2 >= n) return n;

        int gap = 0;
        int current = A[0];
        int counter = 0;

        for (int i = 0; i < n; ++i) {

            if (A[i] == current) {  // match

                counter++;

                if (3 <= counter) {  // more than twice

                    gap++;

                } else {
                    
                    if (gap != 0) {
                        // skip
                        A[i - gap] = A[i];
                    } 

                }
            } else {  // not match
                
                current = A[i];
                counter = 1;
                if (gap != 0) {
                    // skip
                    A[i - gap] = A[i];
                } 
            }
        }


        return n - gap;

    }
};


int main() {

    Solution s;

    int A[6] = {1, 1, 1, 2, 2, 3};
    int n = 6;

    int result = s.removeDuplicates(A, n);

    cout << "The new array length is: " << result << endl;
    cout << "[";
    for (int i = 0; i < result; ++i) {
        cout << A[i] << ", ";
    }
    cout << "]" << endl;


    return 0;
}
