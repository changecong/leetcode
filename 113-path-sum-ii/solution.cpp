/*
 * Filename:      solution.cpp
 * Copyright:     2014, Zhicong Chen
 * Version:       
 * Author:        Zhicong Chen <zhicong.chen@changecong.com>
 * Created at:    Sat Mar 22 18:37:56 2014
 * Modified at:   Wed Mar 26 11:28:06 2014
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
#ifdef DFS


#endif  // DFS
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
       
#ifdef DFS

        vector<vector<int> > result(0);
        if (root == NULL) return result;

        int diff = sum - root->val;

        // if is a leaf
        if (root->left == NULL && root->right == NULL) {  // leaf
            
            if (root->val == sum) {
                vector<int> temp(1, sum);
                result.push_back(temp);
            }

            return result;
        }

        // left
        vector<vector<int> > left = pathSum(root->left, diff);
    
        for (int i = 0; i < left.size(); ++i) {
            left[i].insert(left[i].begin(), root->val);
            result.push_back(left[i]);
        }

        // right
        vector<vector<int> > right = pathSum(root->right, diff);

        for (int i = 0; i < right.size(); ++i) {
            right[i].insert(right[i].begin(), root->val);
            result.push_back(right[i]);
        }

        return result;

#endif  // DFS        
 
    }
};


int main() {

    // Solution s;

    cout << "Too lazy to write a test code!" << endl;

    return 0;
}
