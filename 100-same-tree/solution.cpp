/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 20 16:24:32 2014
 * Modified at:   Thu Mar 20 16:36:00 2014
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
    bool isSameTree(TreeNode *p, TreeNode *q) {

        if (NULL == p && NULL == q) return true;
        else if (NULL == p || NULL == q) return false;

        return isSameTree(p->left, q->left) && p->val == q->val && isSameTree(p->right, q->right);
        
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
