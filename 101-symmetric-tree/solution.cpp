/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 20 16:39:27 2014
 * Modified at:   Thu Mar 20 16:49:51 2014
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
    bool isSymmetric(TreeNode *root, TreeNode* mirror) {

        if (NULL == root && NULL == mirror) return true;
        else if (NULL == root || NULL == mirror) return false;

        return isSymmetric(root->left, mirror->right) && root->val == mirror->val && isSymmetric(root->right, mirror->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        
        // we only need to compare left sub tree and the right subtree;

        if (NULL == root) return true;

        return isSymmetric(root->left, root->right);

    }
};


int main() {

    cout << "Too lazy to write a test case!"<< endl;

    return 0;
}
