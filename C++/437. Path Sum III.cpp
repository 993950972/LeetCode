/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

/*
算法思想：使用递归算法。分四种情况：
1.当前节点已经值已经取了，说明其孩子节点也必须得取（或者所有的都不取），要不然就中间就断了。
2.当前节点未取，其孩子节点可以取也可以不取，如果取了就跟1情况一样，如果不取就跟2情况一样。
上面2中情况又分为2中情况：
1.当前节点值等于sum。
2.当前值不等于sum。
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
    int getPathSum(TreeNode* root, int sum,int flag) {
        if(!root) return 0;
        if(flag && root->val == sum)        //前面取了且当前值等于sum
            return getPathSum(root->left,sum - root->val,1) + getPathSum(root->right,sum - root->val,1) + 1;
        else if(flag)                       //前面取了且当前值不等于sum
        {
            return getPathSum(root->left,sum - root->val,1) + getPathSum(root->right,sum - root->val,1);
        }
        else if(!flag && root->val == sum)  //前面没取且当前值等于sum
        {
            return getPathSum(root->left,sum,0) + getPathSum(root->right,sum,0) + getPathSum(root->left,sum - root->val,1) + getPathSum(root->right,sum - root->val,1) + 1;
        }
        else                                //前面没取且当前值不等于sum
        {
            return getPathSum(root->left,sum,0) + getPathSum(root->right,sum,0) + getPathSum(root->left,sum - root->val,1) + getPathSum(root->right,sum - root->val,1);
        }     
    }
    int pathSum(TreeNode* root, int sum)
    {
        return getPathSum(root, sum,0); 
    }
};

/*
discuss：看到discuss上面写的，方法很好。使用HashMap来实现，其key为前缀和，value为key出现的次数。遍历树，当到达一个节点，检查key为（前缀和 - 目标值）的是否在map中。如果在，则count加上其value值，如果不在，则更新map。 
So the idea is similar as Two sum, using HashMap to store ( key : the prefix sum, value : how many ways get to this prefix sum) , and whenever reach a node, we check if prefix sum - target exists in hashmap or not, if it does, we added up the ways of prefix sum - target into res.
For instance : in one path we have 1,2,-1,-1,2, then the prefix sum will be: 1, 3, 2, 1, 3, let's say we want to find target sum is 2, then we will have{2}, {1,2,-1}, {2,-1,-1,2} and {2}ways.

I used global variable count, but obviously we can avoid global variable by passing the count from bottom up. The time complexity is O(n). This is my first post in discuss, open to any improvement or criticism. :)
*/
Java：
    public int pathSum(TreeNode root, int sum) {
        HashMap<Integer, Integer> preSum = new HashMap();
        preSum.put(0,1);
        helper(root, 0, sum, preSum);
        return count;
    }
    int count = 0;
    public void helper(TreeNode root, int currSum, int target, HashMap<Integer, Integer> preSum) {
        if (root == null) {
            return;
        }
        
        currSum += root.val;

        if (preSum.containsKey(currSum - target)) {
            count += preSum.get(currSum - target);
        }
        
        if (!preSum.containsKey(currSum)) {
            preSum.put(currSum, 1);
        } else {
            preSum.put(currSum, preSum.get(currSum)+1);
        }
        
        helper(root.left, currSum, target, preSum);
        helper(root.right, currSum, target, preSum);
        preSum.put(currSum, preSum.get(currSum) - 1);
    }
