/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Mar 22 17:56:45 2014
 * Modified at:   Sat Mar 22 18:34:11 2014
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

public:
    bool hasPathSum(TreeNode *root, int sum) {

        if (NULL == root) return false;
        
        int current = root->val;

        if (current == sum && root->left == NULL && root->right == NULL) return true;

        bool left = hasPathSum(root->left, sum - current);
        bool right = hasPathSum(root->right, sum - current);
   
        return left || right;
    }
};

int main() {

    cout << "Too lazy to write a test case!" << endl;
    return 0;
}
