/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Fri Mar 21 08:41:44 2014
 * Modified at:   Fri Mar 21 10:47:21 2014
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
#ifdef DFS
    void maxDepth(TreeNode *root, int &depth) {

        if (NULL == root) return;

        int depthL = 0;
        int depthR = 0;
        maxDepth(root->left, depthL);

        maxDepth(root->right, depthR);

        depth = (depthL > depthR) ? depthL + 1 : depthR + 1;        
    }

#endif  // DFS

#ifdef BFS

    void maxDepth(queue<TreeNode*> nodes, int &depth) {

        if (nodes.empty()) return;

        depth++;

        int num = nodes.size();

        while (num-- > 0) {

            TreeNode *temp = nodes.front();

            // pop
            nodes.pop();

            // push in queue
            if (temp->left != NULL) nodes.push(temp->left);
            if (temp->right != NULL) nodes.push(temp->right);
        }

        maxDepth(nodes, depth);

    }

#endif  // BFS

public:
    int maxDepth(TreeNode *root) {

#ifdef DFS        
        int depth = 0;

        if (NULL == root) return depth;

        maxDepth(root, depth);
        
        return depth;
#endif  // DFS

#ifdef BFS
        
        int depth = 0;
        if (NULL == root) return depth;

        queue<TreeNode *> nodes;
        nodes.push(root);

        maxDepth(nodes, depth);

        return depth;
        
#endif  // BFS
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}

