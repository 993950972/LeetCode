/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.

*/

/*
算法思想：使用递归算法，当两个指针均为空，返回空，否则创建一个新节点，其值为两个指针所指节点的值。且新节点的左子树为mergeTrees(t1 == NULL ? NULL:t1->left,t2 == NULL ? NULL:t2->left)，右子树为mergeTrees(t1 == NULL ? NULL:t1->right,t2 == NULL ? NULL:t2->right)。
最后返回新节点。
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
       if(t1 == NULL && t2 == NULL)
           return NULL;
        int val = (t1 == NULL ? 0: t1->val) + (t2 == NULL ? 0: t2->val);
        TreeNode *new_node = new TreeNode(val);
        new_node->left = mergeTrees(t1 == NULL ? NULL:t1->left,t2 == NULL ? NULL:t2->left);
        new_node->right = mergeTrees(t1 == NULL ? NULL:t1->right,t2 == NULL ? NULL:t2->right);
        return new_node;
    }
};
