/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

/*
算法思想：直接前序遍历，放入vector中，此时vector中的数据是从小到大排序的。然后使用unordered_map来统计每个数出现的次数，然后遍历unordered_map记录其出现次数的最大值max，再一次遍历unordered_map，如果其key的value等于max，说明该key为众数，放入结果vector中。
*/
public:
    vector<int> vec;
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left)
        {
            preorder(root->left);
        }
        vec.push_back(root->val);
        if(root->right)
        {
            preorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        preorder(root);
        unordered_map<int,int> um;
        int sz = vec.size();
        vector<int> ans;
        for(int i = 0;i < sz;i++)
        {
            um[vec[i]]++;
        }
        int max = 0;
        for(unordered_map<int,int>::iterator it = um.begin();it != um.end();it++)
        {
            if(max < (*it).second)
                max = (*it).second;
        }
        for(unordered_map<int,int>::iterator it = um.begin();it != um.end();it++)
        {
            if((*it).second == max)
               ans.push_back((*it).first);
        }
        return ans;
    }
};

/*
discuss:
算法1：前序遍历两次，第一次计算出树中出现相同数的最大次数mfq，第二次前序遍历判断当出现相同数的次数为mfq时，将其放入结果集中。
Key Observation: Obviously, it is very easy to get modes from a sorted array since all duplicates are consecutive.

An in-order traversal of BST gives exactly a sorted sequence.

Naturally, in-order traversal takes O(N) time. To achieve O(1) extra space, we cannot store the array of in-order node values. But all modes can be found in two traversals:

	1.Find max frequency of node values mfq by counting and update number of duplicates.
	2.Store a mode into result vector<int> modes whenever the duplicates match mfq from first traversal.
Note: we can accomplish both traversals by keeping 2 variables pre (previous node value) and cnt (count of current duplicates):

	Update cnt by ++(cnt*=(r->val==pre)), i.e., r->val==pre? ++cnt : cnt=1;
	Update pre by simply copying pre = r->val;
*/

   vector<int> modes;
    
    vector<int> findMode(TreeNode* r) {
      int mfq/*max freq*/, pre/*previous val*/, cnt/*duplicates count*/;
      getMaxFreq(r, mfq=0, pre, cnt=0); // in-order traversal to get max frequency
      getMode(r, mfq, pre, cnt=0);      // in-order traversal to get all modes
      return modes;
    }
    
    void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
      if (!r) return;
      getMaxFreq(r->left, mfq, pre, cnt);
      getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, ++(cnt*=(r->val==pre)));
    }
    
    void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
      if (!r) return;
      getMode(r->left, mfq, pre, cnt);
      if (mfq == ++(cnt*=(r->val==pre))) modes.push_back(r->val);
      getMode(r->right, mfq, pre=r->val, cnt);
    }
	
	
	/*
	discuss：一次前序遍历就将数放入List中。
	*/
	public class Solution {
    Integer prev = null;
    int count = 1;
    int max = 0;
    public int[] findMode(TreeNode root) {
        if (root == null) return new int[0];
        
        List<Integer> list = new ArrayList<>();
        traverse(root, list);
        
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) res[i] = list.get(i);
        return res;
    }
    
    private void traverse(TreeNode root, List<Integer> list) {
        if (root == null) return;
        traverse(root.left, list);
        if (prev != null) {
            if (root.val == prev)
                count++;
            else
                count = 1;
        }
        if (count > max) {
            max = count;
            list.clear();
            list.add(root.val);
        } else if (count == max) {
            list.add(root.val);
        }
        prev = root.val;
        traverse(root.right, list);
    }
}