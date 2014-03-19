/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Tue Mar 18 21:56:53 2014
 * Modified at:   Wed Mar 19 15:05:13 2014
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
    vector<TreeNode *> generateTrees(int head, int tail) {

        vector<TreeNode *> result;

        if (head == tail) {  // same number
            TreeNode *root = new TreeNode(head);
            result.push_back(root);
        } else {

            for (int i = head; i <= tail; ++i) {

                
                if (i == head) { // first
                    // only consider right nodes
                    
                    vector<TreeNode *> right = generateTrees(i+1, tail);
                    
                    for (int j = 0; j < right.size(); ++j) {
                        
                        TreeNode *root = new TreeNode(i);
                        
                        root->right = right[j];
                        result.push_back(root);
                        
                    }

                } else if(i == tail) {
                    
                    // only consider left nodes
                    
                    vector<TreeNode *> left = generateTrees(head, i-1);
                    
                    for (int j = 0; j < left.size(); ++j) {

                        TreeNode *root = new TreeNode(i);

                        root->left = left[j];

                        result.push_back(root);
                    }

                } else { // middle
                    
                    // left and right
                    vector<TreeNode *> left = generateTrees(head, i - 1);
                    vector<TreeNode *> right = generateTrees(i + 1, tail);

                    for (int l = 0; l < left.size(); ++l) {

                        for (int r = 0; r < right.size(); ++r) {
                            
                            TreeNode *root = new TreeNode(i);

                            root->left = left[l];
                            root->right = right[r];

                            result.push_back(root);
                            
                        }
                    }
                }
            }
        }
        
        return result;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        
        vector<TreeNode* > result;
        

        if (n == 0) {
            TreeNode *root = NULL;  // NULL
            result.push_back(root);
            return result;
        }

        result = generateTrees(1, n);

        return result;
    }
};


int main() {

    cout << "Too lazy to write a test case!" << endl;

    return 0;
}
