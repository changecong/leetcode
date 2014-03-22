/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 23:09:29 2014
 * Modified at:   Fri Mar 21 23:29:19 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>

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
    bool isBalanced(TreeNode *root, int &depth) {

        if (NULL == root) return true;

        int l_depth = 0;
        int r_depth = 0;
        if (isBalanced(root->left, l_depth) && isBalanced(root->right, r_depth)) {
            switch(l_depth - r_depth) {

            case -1:
            case 0:
            case 1:  // balanced
                depth = (l_depth > r_depth) ? l_depth + 1 : r_depth + 1;
                return true;
                break;
            default:
                return false;
                break;
            }
        }

        return false;        
    }

public:
    bool isBalanced(TreeNode *root) {

        int depth = 0;
        return isBalanced(root, depth);
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
