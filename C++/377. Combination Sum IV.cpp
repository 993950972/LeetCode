/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

	nums = [1, 2, 3]
	target = 4

	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

/*
算法思想：
方法1：深度搜索，会超时。深度搜索步骤：1）写出退出递归条件；2）基本操作。注意：递归函数中参数选择，退出条件、基本操作。
方法2：使用动态规划，从上往下递归或者从下往上。动态规划为了减少时间复杂度，避免重复计算同样的操作，可以使用记录数组。
*/
//深度搜索方法，超时
class Solution {
public:
    vector<int> nums;
    int sz,target,ans = 0;
    void dfs(int sum,int k)
    {
        if(sum >= target || k >= sz)
        {
            if(sum == target && k < sz)
                ans++;
            return;
        }
        for(int i=0;i<sz;i++){
            dfs(sum+nums[i],i);
        }
        
    }
    int combinationSum4(vector<int>& nums0, int goal) {
        sz = nums0.size(),target = goal;
        nums = nums0;
        for(int i=0;i<sz;i++)
            dfs(nums[i],i);
        return ans;
    }
};

//动态规划，置顶向下
class Solution {
public:
    int *dp,sz;
    int combinationSum4(vector<int>& nums, int target) {
        dp = new int[target + 1];
        sz = nums.size();
        for(int i = 0;i <= target;i++)
        {
            dp[i] = -1;
        }
        dp[0] = 1;
        return helper(nums,target);
    }
private:
    int helper(vector<int>& nums,int target)
    {
        if(dp[target] != -1)
            return dp[target];
        int res = 0;
        for(int i = 0;i < sz;i++)
        {
            if(target >= nums[i])
            {
                res += helper(nums,target - nums[i]);
            }
        }
        dp[target] = res;
        return res;
    }
};

//动态规划，置底向上
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> dp(target + 1,0);
        dp[0] = 1;
        for(int i = 1;i <= target;i++)
        {
            for(int j = 0;j < sz;j++)
            {
                if(i >= nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }

};