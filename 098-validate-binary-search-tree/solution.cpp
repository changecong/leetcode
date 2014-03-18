/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 22:14:52 2014
 * Modified at:   Mon Mar 17 22:59:44 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <climits>

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
    bool isValidBST(TreeNode *node, int max, int min) {

        if (NULL == node) return true;

        int root  = node->val;
        
        // should not equal
        return root < max && root > min && isValidBST(node->left, root, min) && isValidBST(node->right, max, root);

    }

public:
    bool isValidBST(TreeNode *root) {

        return isValidBST(root, INT_MAX, INT_MIN);
        
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
