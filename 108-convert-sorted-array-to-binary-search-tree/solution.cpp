/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 16:01:02 2014
 * Modified at:   Fri Mar 21 16:25:25 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int len) {

        TreeNode *result = NULL;
        if (num.empty()) return result;
        if (0 == len) return result;

        int mid = len / 2 + start;

        result = new TreeNode(num[mid]);

        int left_start = start;
        int left_len = mid - left_start;
        int right_start = mid + 1;
        int right_len = len - left_len - 1;  // 1 is for mid

        result->left = sortedArrayToBST(num, left_start, left_len);
        result->right = sortedArrayToBST(num, right_start, right_len);

        return result;        
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {

        return sortedArrayToBST(num, 0, num.size());
        
    }
};

int main() {
    
    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
