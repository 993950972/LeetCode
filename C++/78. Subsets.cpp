/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
	If nums = [1,2,3], a solution is:

	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]

*/

/*
算法思想：使用深度搜索。
深度搜索，一般使用递归。1）退出条件确定；2）基本操作。
*/

class Solution {
public:
    int sz;
    set<vector<int>> vec;
    void dfs(vector<int>& nums,vector<int> ans,int k)
    {
        vec.insert(ans);
        if(k < 0 || k >= sz)
        {
            return;
        }
        vector<int> temp = ans;	//保存上一次值，用于下面回溯
        ans.push_back(nums[k]);
        dfs(nums,ans,k + 1);
        ans = temp;		//回溯
        dfs(nums,ans,k + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec0;
        sz = nums.size();
        dfs(nums,vec0,0);
        vector<vector<int>> ans(vec.begin(),vec.end());
        return ans;
    }
};