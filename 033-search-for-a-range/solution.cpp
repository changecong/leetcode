/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Feb  4 23:04:18 2014
 * Modified at:   Fri Feb  7 11:07:32 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> result;
        
        if (0 == n) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int mid = n / 2;
        int middle = A[mid];
        int head = A[0];
        int tail = A[n-1];

        bool inLeft = false;
        bool inRight = false;

        if (1 == n && A[0] == target) {
            result.push_back(0);
            result.push_back(0);
            return result;
        }

        if (target > tail || target < head) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }



        vector<int> left = searchRange(A, mid, target);
        if (left[0] != -1 && left[1] != -1) {
            inLeft = true;
        } else {
            // not in right part;
            inLeft = false;
        }

        vector<int> right = searchRange(A + mid, n - mid, target);
        if (right[0] != -1 && right[1] != -1) {
            inRight = true;
            right[0] += mid;
            right[1] += mid;
        } else {
            // not in right part;
            inRight = false;
        }

        if (inLeft && inRight) {
            result.push_back(left[0]);
            result.push_back(right[1]);
        } else if (inLeft && !inRight) {
            result = left;
        } else if (!inLeft && inRight) {
            result = right;
        } else {
            result.push_back(-1);
            result.push_back(-1);
        }

        return result;

    }
};


int main() {

    Solution s;

    int A[6] = {5, 7, 8, 8, 8, 10};
    int n = 6;
    int target = 5;

    vector<int> result = s.searchRange(A, n, target);

    cout << "The result is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
