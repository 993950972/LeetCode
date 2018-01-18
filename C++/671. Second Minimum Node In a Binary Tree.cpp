/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
	Input: 
		2
	   / \
	  2   5
		 / \
		5   7

	Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
	Input: 
		2
	   / \
	  2   2

	Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/

/*
算法思想：递归算法，递归退出条件是，当树根节点为空或者其没有孩子节点，说明树中肯定找不到其第二小的数，故返回一个最大值，然后递归其左右子树。如果左子树的值不等于根节且右子树的值都不等于当前节点的值，说明第二小的数为左子树节点与右子树节点值中的较小者；如果其中一棵子树节点值与根节点相等，则递归该子树，其返回值与另一个比较，返回其中较小者，如果左右子树节点值均等于当前节点值，则递归左右子树，返回两者中较小值。
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
   
    int getfindSecondMinimumValue(TreeNode* root) {
        if(!root || !root->left) return INT_MAX;
        if(root->left->val != root->val && root->right->val != root->val) return min(root->left->val,root->right->val);
        else if(root->left->val != root->val) return min(root->left->val,getfindSecondMinimumValue(root->right));
        else if(root->right->val != root->val) return min(root->right->val,getfindSecondMinimumValue(root->left));
        else return min(getfindSecondMinimumValue(root->left),getfindSecondMinimumValue(root->right));
    }
    int findSecondMinimumValue(TreeNode* root)
    {
        int ans = getfindSecondMinimumValue(root);
        if(ans == INT_MAX || ans == root->val)
            return -1;
        return ans;
    }
	
	/*
	discuss：深度搜索，与寻找二叉树中最小值类似，唯一不同是要找的值必须与根节点不相同。
	This question is very similar to searching for minimum value in the Binary Tree.
The only requirement is that this value must be different from the root value, k.

If the root value of a subtree == k, 
         keep searching its children.
else, 
         return the root value because it is the minimum of current subtree.
	*/
	
	class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int ans = minval(root, root->val);
        return ans;
    }
private:
    int minval(TreeNode* p, int first) {
        if (p == nullptr) return -1;
        if (p->val != first) return p->val;
        int left = minval(p->left, first), right = minval(p->right, first);
        // if all nodes of a subtree = root->val, 
        // there is no second minimum value, return -1
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};
};