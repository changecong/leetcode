/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 14:58:48 2014
 * Modified at:   Fri Mar 21 15:28:27 2014
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
    TreeNode *buildTree(vector<int> &preorder, int preorder_start, 
                        vector<int> &inorder, int inorder_start,
                        int len) {

        TreeNode *result = NULL;

        if (preorder.size() != inorder.size()) return result;
        if (len == 0) return result;
        
        // find the root
        int root = preorder[preorder_start];

        // split in order
        int idx = inorder_start;
        while(inorder[idx] != root) idx++;
        
        int left_len = idx - inorder_start;
        int left_inorder_start = inorder_start;
        idx++;
        int right_inorder_start = idx;
        int right_len = len - left_len - 1;  // 1 is the root

        // split preorder
        int left_preorder_start = preorder_start + 1;
        int right_preorder_start = left_preorder_start + left_len;

        // gen root node
        result = new TreeNode(root);
        result->left = buildTree(preorder, left_preorder_start,
                                inorder, left_inorder_start,
                                left_len);
        result->right = buildTree(preorder, right_preorder_start,
                                  inorder, right_inorder_start,
                                  right_len);

        return result;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        return buildTree(preorder, 0,
                         inorder, 0,
                         inorder.size());

    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
