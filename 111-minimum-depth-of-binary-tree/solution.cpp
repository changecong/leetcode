/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Mar 22 17:09:04 2014
 * Modified at:   Sat Mar 22 17:49:05 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <queue>

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
    int minDepth(queue<TreeNode* > nodes) {

        int depth = 0;
        // use BFS, when the first leaf found, return the depth
        if (nodes.empty()) return depth;

        int num = nodes.size();

        while (num-- > 0) {
            
            TreeNode *node = nodes.front();

            // pop
            nodes.pop();

            if (node->left == NULL && node->right == NULL) {  // no child
                return 1;
            } 

            if (node->left != NULL) nodes.push(node->left);
            if (node->right != NULL) nodes.push(node->right);

        }
        
        return minDepth(nodes) + 1;

    }


public:
    int minDepth(TreeNode *root) {
        
        if (NULL == root) return 0;

        queue<TreeNode *> nodes;
        nodes.push(root);

        return minDepth(nodes);

    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
