/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 15:31:42 2014
 * Modified at:   Fri Mar 21 15:57:33 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <vector>
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
    vector<vector<int> > levelOrderBottom(queue<TreeNode*> &nodes) {

        vector<vector<int> > result(0);
        if (nodes.empty()) return result;
        
        int num = nodes.size();

        vector<int> temp;
        while (num-- > 0) {
            
            TreeNode *node = nodes.front();

            // pop
            nodes.pop();

            temp.push_back(node->val);

            if (NULL != node->left) nodes.push(node->left);
            if (NULL != node->right) nodes.push(node->right);
        }

        // now we have temp
        
        result = levelOrderBottom(nodes);
        result.push_back(temp);

        return result;
    }

public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int> >result(0);
        if (NULL == root) return result;

        queue<TreeNode* > nodes;
        nodes.push(root);

        return levelOrderBottom(nodes);
        
    }
};

int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
