/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;


class Solution {

private:
	stack<TreeNode*> myStack;


public:
    vector<int> inorderTraversal(TreeNode* root) {

    	vector<int> result;

    	TreeNode* node = root;

    	while(node != NULL || !myStack.empty()) {

    		// traverse the left subtree
    		while(node != NULL) {

    			myStack.push(node);
    			node = node->left;
    		}

    		if (!myStack.empty()) {

    			node = myStack.top();
    			myStack.pop();

    			result.push_back(node->val);
    			node = node->right;
    		}
    	}

    	return result;

    }
};