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
    
	private Stack<TreeNode> stack = new Stack<TreeNode>();

    // Recursive solution is trivial, could you do it iteratively?

    public List<Integer> inorderTraversal(TreeNode root) {

    	List<Integer> result = new ArrayList<Integer>();

    	TreeNode node = root;

    	while (node != null || !stack.empty()) {

    		// traverse the left subtree
    		while (node != null) {
    			stack.push(node);
    			node = node.left;
    		}

    		if (!stack.empty()) {
    			node = stack.pop();
    			result.add(node.val);

    			// visit the right subtree
    			node = node.right;
    		}
    	}

    	return result;
    }
}