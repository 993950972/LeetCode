/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

	1.The sum of node values in any subtree won't exceed the range of 32-bit integer.
	2.All the tilt values won't exceed the range of 32-bit integer.
*/

/*
算法思想：使用递归，如果树为空，返回0，否则返回左子树的和与右子树的和的差的绝对值与左子树的倾斜度和右子树的倾斜度的和。
*/
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
public:
    int findTilt(TreeNode* root) {
        if(!root) return 0;        
        return abs(getSum(root->left) - getSum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
    int getSum(TreeNode* root)
    {
        if(!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
};

/*
discuss：使用后序遍历。题目符合左右根的思想，使用后序遍历最好。
*/
public class Solution {
    int result = 0;
    
    public int findTilt(TreeNode root) {
        postOrder(root);
        return result;
    }
    
    private int postOrder(TreeNode root) {
        if (root == null) return 0;
        
        int left = postOrder(root.left);
        int right = postOrder(root.right);
        
        result += Math.abs(left - right);
        
        return left + right + root.val;
    }
}