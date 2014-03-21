/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 10:58:53 2014
 * Modified at:   Fri Mar 21 14:50:40 2014
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
    TreeNode *buildTree(vector<int> &inorder, int inorder_start,
                        vector<int> &postorder, int postorder_start,
                        int len) {

        TreeNode *result = NULL;

        if (inorder.size() != postorder.size()) return result;
        if (0 == len) return result;

        // get the root
        int root = postorder[postorder_start + len -1];

        // find the root in inorder, while split the vector

        int idx = inorder_start;
        
        while (inorder[idx] != root) idx++;

        int left_len = idx - inorder_start;
        int left_inorder_start = inorder_start;
        int right_len = len - left_len - 1;
        int right_inorder_start = idx + 1;

        // equal
        result = new TreeNode(root);
        
        // split postorder
        int left_postorder_start = postorder_start;
        int right_postorder_start = postorder_start + left_len;

        result->left = buildTree(inorder, left_inorder_start, 
                                 postorder, left_postorder_start,
                                 left_len);
        result->right = buildTree(inorder, right_inorder_start,
                                  postorder, right_postorder_start,
                                  right_len);

        return result;
        
    }


public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        return buildTree(inorder, 0,
                         postorder, 0,
                         inorder.size());
        
    }


    void display(TreeNode *root) {
        
        if (NULL == root) return;

        display(root->left);
        
        cout << root->val << " ";

        display(root->right);
        
    }

};


int main() {

    Solution s;

    int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[9] = {1, 2, 4, 3, 7, 9, 8, 6, 5};

    vector<int> inorder(A, A+9);
    vector<int> postorder(B, B+9);

    TreeNode *result = s.buildTree(inorder, postorder);

    s.display(result);
    cout << endl;

    // cout << "Too lazy to write a test cast!" << endl;

    return 0;
}
