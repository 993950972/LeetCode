/*
算法思想：题目是要求当前数与比之大的所有数的和，根据二叉搜索树的特点，很容易想到后序遍历，后序遍历将从大到小排序，然后计算和就可以。
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
    TreeNode* root;
    TreeNode* convertBST(TreeNode* p) {
        root = p;
        if(!root)
            return root;
        pastorder(root);
        return root;
    }
    int sum = 0;
    void pastorder(TreeNode* root)		//后序遍历
    {
        if(!root)
            return;
        if(root->right)
        {
            pastorder(root->right);	
        }
        sum += root->val;				//求sum = root->val + sum（sum为大于root->val的所有数的和），更新当前节点值为sum。
        root->val = sum;        
        if(root->left)
        {
            
             pastorder(root->left);
        } 
    }
};