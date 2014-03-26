/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Wed Mar 26 11:33:27 2014
 * Modified at:   Wed Mar 26 12:32:59 2014
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
    void flatten(TreeNode *&root, TreeNode* &left_most) {

        // 
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {  // leaf

            left_most = root;
            return;
        } else if (root->left == NULL) {  // right only

             // recursive 
            flatten(root->right, left_most);
            return;
        } else {

            // store the right node
            TreeNode *right = root->right;
            TreeNode *temp = NULL;
            
            // move the left node to right
            root->right = root->left;
            root->left = NULL;  // if not Runtime Error
            
            // recursive 
            flatten(root->right, temp);
            
            temp->right = right;
            
            flatten(temp->right, temp);
            
            left_most = temp;
            
            return;
        }
    }

public:
    void flatten(TreeNode *root) {
        
        TreeNode *left_most = NULL;
        flatten(root, left_most);

    }
};


int main() {

    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    s.flatten(root);
    
    TreeNode *node = root;
    while(node != NULL) {
        cout << node->val << " -> ";
        node = node->right;
    }
    cout << endl;

    return 0;
}
