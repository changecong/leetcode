/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Mon Mar 17 21:58:16 2014
 * Modified at:   Mon Mar 17 22:08:57 2014
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
public:
    vector<int> inorderTraversal(TreeNode *root) {
   
        vector<int> result;

        if (NULL == root) return result;
        
        // left
        vector<int> left = inorderTraversal(root->left);

        for (int i = 0; i < left.size(); ++i) result.push_back(left[i]);

        // middle
        result.push_back(root->val);

        // right
        vector<int> right = inorderTraversal(root->right);

        for (int i = 0; i < right.size(); ++i) result.push_back(right[i]);
        
        return result;

    }
};

int main() {

    // Solution s;

    cout << "Too lazy to write a test case" << endl;

    return 0;
}
