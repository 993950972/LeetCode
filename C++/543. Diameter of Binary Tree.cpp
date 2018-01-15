/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/

/*
算法思想：分两种情况：1.根节点加入；2.根节点不加入。如果根节点加入，则返回左子树的深度与右子树的深度和；如果根节点不加入，则其左子树和右子树又与前面一样分两种情况，使用递归。
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = getDepth(root->left) + getDepth(root->right);     //加了头节点
        int a = max(res,diameterOfBinaryTree(root->left));
        return max(a,diameterOfBinaryTree(root->right));
    }
    int getDepth(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(getDepth(root->left),getDepth(root->right));
    }
};
