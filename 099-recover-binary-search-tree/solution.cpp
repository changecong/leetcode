/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Thu Mar 20 14:08:33 2014
 * Modified at:   Thu Mar 20 16:22:10 2014
 * Modified by:   Zhicong Chen <zhicong.chen@changecong.com>
 * Status:        Experimental, do not distribute.
 * Description:   
 *
 */

#include <iostream>
#include <algorithm>
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

#ifdef N_SPACE
    vector<int> inorderTree(TreeNode* root) {
        
        vector<int> result;

        if (NULL == root) {
            
            return result;
        }
        
        vector<int> left = inorderTree(root->left);
    
        vector<int>::iterator it = left.begin();
        while (it != left.end()) result.push_back(*it++);
        
        
        result.push_back(root->val);
        
        vector<int> right = inorderTree(root->right);
        
        it = right.begin();
        while (it != right.end()) result.push_back(*it++);
        
        return result;
    }

    void recoverTree(TreeNode *root, vector<int> &nodes) {
        
        if (NULL == root) return;

        recoverTree(root->left, nodes);
        
        root->val = nodes.front();
        nodes.erase(nodes.begin());

        recoverTree(root->right, nodes);
    }

#endif  // N_SPACE

#ifdef CONSTANT_SPACE
    void inorderTree(TreeNode *root, TreeNode *&previous, 
                     TreeNode *&node_1, TreeNode *&node_2) {

        if (NULL == root) return;

        // left
        inorderTree(root->left, previous, node_1, node_2);

        if (previous != NULL && previous->val > root->val) {
            node_2 = root;
            if (node_1 == NULL) node_1 = previous;
            
        }

        previous = root;

        // right
        inorderTree(root->right, previous, node_1, node_2);
        
        

    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
#endif  // CONSTANT_SPACE

public:
    void recoverTree(TreeNode *root) {
        
#ifdef N_SPACE
        
        // this method works for every condition 
        // when a binary search tree is in wrong order
   
        if (NULL == root) return;
        
        vector<int> nodes = inorderTree(root);
    
    sort(nodes.begin(), nodes.end());
    
    recoverTree(root, nodes);
    
#endif  // N_SPACE
        
#ifdef CONSTANT_SPACE

    if (NULL == root) return;

    // base on the question, there should be exactly two nodes which are swapped.
    TreeNode *node_1 = NULL;
    TreeNode *node_2 = NULL;
    TreeNode *previous = NULL;

    inorderTree(root, previous, node_1, node_2);

    if (node_1 && node_2) {  // no need
        swap(node_1->val, node_2->val);
    }
#endif  // CONSTANT_SPACE

    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
