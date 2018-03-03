/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

	1.The size of the BST will be between 2 and 100.
	2.The BST is always valid, each node's value is an integer, and each node's value is different.
*/

/*
算法思想：由于是BST树，其性质是前序遍历生成的数据序列是从小到大的，而Minimum Distance肯定是在相邻两个数据差值。
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
    vector<int> ret;
    void inOrderTraverse(TreeNode* root)    //中序遍历，生成的数据序列放入vector中，此时vector中数据有有序（从小到大）
    {
        if(root)
        {
            inOrderTraverse(root->left);
            ret.push_back(root->val);
            inOrderTraverse(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
            inOrderTraverse(root);
            int min_num = INT_MAX;
            for(int i = 1;i < ret.size();i++)  //循环遍历vector，找出最小difference。
            {
                min_num = min(min_num,ret[i] - ret[i - 1]);
            }
            return min_num;
        }
};