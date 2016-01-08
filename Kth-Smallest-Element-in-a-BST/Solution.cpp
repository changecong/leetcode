/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

  struct Result {
    int val;
  };    

public:

  int kthSmallest(TreeNode* root, int k) {
    Result* result = NULL;
    int position = 0;

    findKthSmallest(root, k, position, result);
    return result->val;
  }

private:

  /**
   * for the result, must pass in the reference of the pointer
   */
  void findKthSmallest(TreeNode* node, int k, int& position, Result*& result) {
    if (node->left != NULL) {
      findKthSmallest(node->left, k, position, result);
      if (result != NULL) {
        return;
      }
    }

    if (k == ++position) {
      result = new Result();
      result->val = node->val;
      return;
    }

    if (node->right != NULL) {
      findKthSmallest(node->right, k, position, result);
      if (result != NULL) {
        return;
      }
    }

    return;
  }
};
