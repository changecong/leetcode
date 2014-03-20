/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 20 16:59:33 2014
 * Modified at:   Thu Mar 20 17:19:49 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <queue>
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

    vector<vector<int> > levelOrder(queue<TreeNode*> nodes) {

        vector<vector<int> > result(0);
        if (nodes.empty()) return result;

        int qsize = nodes.size();

        vector<int> current_level;
        while (qsize-- > 0) {

            TreeNode *current = nodes.front();
            nodes.pop();
            current_level.push_back(current->val);

            if (current->left != NULL) nodes.push(current->left);
            if (current->right != NULL) nodes.push(current->right);            
        }

        result = levelOrder(nodes);
        
        result.insert(result.begin(), current_level);

        return result;

    }

public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int> > result(0);
        if (NULL == root) return result;

        queue<TreeNode* > nodes;
        nodes.push(root);

        return levelOrder(nodes);
        
    }
};

int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
