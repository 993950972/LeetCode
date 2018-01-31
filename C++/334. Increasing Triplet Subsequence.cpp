/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

/*
算法思想：贪心法。循环遍历数组，pre记录的当前长度的最小数，curr记录的是当前第二小的数，如果有大于curr的，则说明有increasingTriplet为true，否则为false。
如果使用动态规划法按求解最长单调递增数列的长度解也可以，容易超时，且不符合题意。
Starting from left to right, the numbers could lie in range [-----] for any small<big<thirdvalue
-----small< -----big< -----thirdvalue
a) if currentelement is less than small : update small to currentelement now the range for big can expand between new small and big
b) if currentelement is between small and bigand less than current big : update big to currentelement now the range for thirdvalue can be any number greater than big
c) if currentelement is greater than big: we found 3 such values return true
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3)
            return false;
        int pre = INT_MAX,curr = INT_MAX;
        for(int i = 0;i < sz;i++)
        {
            if(nums[i] <= pre)
            {
                pre = nums[i];
            }
            else if(nums[i] <= curr)
            {
                curr = nums[i];
            }
            else
                return true;
        }
        return false;
    }
};

/*
算法思想：动态规划法
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size(),maxnum = 0;
        if(sz < 3)
            return false;
        int i;
        for(i = 0;i < sz - 1;i++)
        {
            if(nums[i] < nums[i + 1])
                break;
        }
        if(i >= sz - 1)
            return  false;
        vector<int> dp(sz + 1,1);
        for(int i = 0;i < sz;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
                if(dp[i] >= 3)
                    return true;
            }
        }
        return false;
    }
};