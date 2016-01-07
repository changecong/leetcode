/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * position of current node 
     */
    private intposition = 0;

    public int kthSmallest(TreeNode root, int k) {
	return findkthSmallest(root, k).intValue();
    }

    /**                                                           
     *                                                                                                                                              
     */
    public Integer findkthSmallest(TreeNode node, int k) {
        Integer result;

        if (node.left != null) {
            result = findkthSmallest(node.left, k);
            if (result != null) {
                return result;
            }
        }

        if (k == ++this.position) {
            return new Integer(node.val);
        }

        if (node.right != null) {
            result = findkthSmallest(node.right, k);
            if (result != null) {
                return result;
            }
        }

        return null;
    }
}
