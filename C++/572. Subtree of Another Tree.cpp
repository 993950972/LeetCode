/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

*/

/*
算法思想：先写一个判断树相等的函数，然后使用递归法来判断该树是否与树t相等。
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
    bool isEqual(TreeNode* s, TreeNode* t)
    {
       if(!s && !t || s && t && s->val == t->val && isEqual(s->left,t->left) && isEqual(s->right,t->right)) return true;
       return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isEqual(s,t)) 
            return true;
        if(!s && t || s && !t) 
            return false;
        return (isSubtree(s->left,t) || isSubtree(s->right,t));
    }
};