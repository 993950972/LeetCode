/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
*/

/*
算法思想：使用递归，考虑差值绝对值最小只可能出现在：根节点与其孩子节点、根节点与其左子树的右子树的右子树... 、根节点与其右子树的左子树的左子树...，对于每一颗数都是如此，故使用递归算法。
如果树的左、右子树非空：就递归其左子树、右子树，同时也计算根节点与其他点的差值的绝对值的最小值，返回三者中的最小值；
如果树的左子树非空，右子树为空：递归其左子树，同时也计算根节点与其他点的差值的绝对值的最小值，返回两者中的最小值；其右子树非空，左子树为空，同理。
如果树的左子树和右子树均为空，说明已经递归到其叶子节点，则返回一个最大值。
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
    #define MAX_NUM 0x3fffffff
    int getMinimumDifference(TreeNode* root) {
        int lright_val,rleft_val,curr_min,next_min;
        TreeNode* p;
        if(root->left && root->right)       //左子树、右子树均不为空
        {
            p = root->left;
            lright_val = p->val;
            while(p->right)
            {
                p = p->right;
                lright_val = p->val;
            }
            p = root->right;
            rleft_val = p->val;
            while(p->left)
            {
                p = p->left;
                rleft_val = p->val;
            }            
            curr_min = min(abs(root->val - lright_val),abs(root->val - rleft_val));    //计算根节点到其他点的最小值
            next_min = min(getMinimumDifference(root->left),getMinimumDifference(root->right)); //递归计算其左子树、右子树的最小值
            return min(curr_min,next_min);              //返回两者中的最小值
        }
        else if(root->right)                            //左子树为空、右子树非空的情况
        {
            p = root->right;
            rleft_val = p->val;
            while(p->left)
            {
                p = p->left;
                rleft_val = p->val;
            }
            curr_min = abs(root->val - rleft_val);       //计算根节点到其他点的最小值
            next_min = getMinimumDifference(root->right);//递归计算其左子树的最小值
            return min(curr_min,next_min);               //返回两者中的最小值
        }
        else if(root->left)                              //右子树为空、左子树非空的情况（与上类似）
        {
            p = root->left;
            lright_val = p->val;
            while(p->right)
            {
                p = p->right;
                lright_val = p->val;
            }
            curr_min = abs(root->val - lright_val);
            next_min = getMinimumDifference(root->left);
            return min(curr_min,next_min);
        }
        else                                            //左右子树均空，说明是叶子节点，不能形成差值，故返回一个最大值即可
        {
            return MAX_NUM;
        }
    }
};

/*
discuss：考虑二叉搜索树前序遍历是从小到大排序的，要求差值的绝对值最小值就一定是在相邻的两个数之间，故前序遍历，记录每次的差值最小值即可，遍历完成直接返回。
*/

class Solution {
    int min_dif = INT_MAX, val = -1;
public:
int getMinimumDifference(TreeNode* root) {
    if (root->left != NULL) getMinimumDifference(root->left);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) getMinimumDifference(root->right);
    return min_dif;
}