/*
You need to find the largest value in each row of a binary tree.

Example:
	Input: 

			  1
			 / \
			3   2
		   / \   \  
		  5   3   9 

	Output: [1, 3, 9]
*/

/*
算法思想：层次遍历，使用两个队列进行层次遍历，当第一个队列为空，说明该层次已经遍历完，继续遍历第二个队列。
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q,q1;
        vector<int> ans;
        int temp,maxnum;
        TreeNode* node;
        if(!root)
            return ans;
        q.push(root);
        while(!q.empty() || !q.empty())
        {
            maxnum = INT_MIN;
            while(!q.empty())
            {
                node = q.front();
                q.pop();
                if(node->val > maxnum)
                    maxnum = node->val;
                if(node->left)
                    q1.push(node->left);
                if(node->right)
                    q1.push(node->right);
            }
            ans.push_back(maxnum);
            swap(q,q1);
        }
        return ans;
    }
};