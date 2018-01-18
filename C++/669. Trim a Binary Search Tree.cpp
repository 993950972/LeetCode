/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
	Input: 
		1
	   / \
	  0   2

	  L = 1
	  R = 2

	Output: 
		1
		  \
		   2
Example 2:
	Input: 
		3
	   / \
	  0   4
	   \
		2
	   /
	  1

	  L = 1
	  R = 3

	Output: 
		  3
		 / 
	   2   
	  /
	 1
*/

/*
算法思想：一般遇到树的题目，要么是遍历树，要么直接递归，递归是树的天性。这里对树进行剪枝操作，因为所给的树是BST，故如果当前节点的值大于R（右边界），则说明其右子树肯定大于R，故只需要递归返回trimBST(root->left,L,R)；如果当前值小于L（左边界），说明其左子树值肯定小于L，故则只需要返回trimBST(root->right,L,R)，如果当前值在两者之间（包括L,R），则root->left = trimBST(root->left,L,R); root->right = trimBST(root->right,L,R);且返回root。
树的定义就是递归，所以一般使用递归来解决。其前序、中序、后序、层次遍历以及求深度等算法很重要。
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
    TreeNode *new_root;
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return root;
        if(root->val > R) return trimBST(root->left,L,R);
        if(root->val < L) return trimBST(root->right,L,R);
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
};