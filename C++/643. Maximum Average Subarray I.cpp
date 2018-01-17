/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
	Input: [1,12,-5,-6,50,3], k = 4
	Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
	1.1 <= k <= n <= 30,000.
	2.Elements of the given array will be in the range [-10,000, 10,000].
*/

/*
算法思想：遍历数组，使用每个元素保存的是前n个元素的和，然后遍历新数组，找出其k个连续元素和最大值。
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sz = nums.size();
        double ans;
        for(int i = 1;i < sz;i++)
        {
            nums[i] += nums[i - 1];
        }
        double max = nums[k - 1],temp;
        for(int i = k;i < sz;i++)
        {
            temp = nums[i] - nums[i - k];
            if(max < temp)
                max = temp;
        }
        ans = max/k;
        return ans;
    }
};

/*
discuss：代码更加简洁。
*/
double findMaxAverage(vector<int>& nums, int k) {
        double sum=0, res=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            if(i<k) sum+=nums[i];
            else {
                res=max(sum, res);
                sum+=nums[i]-nums[i-k];
            }
        }
        res=max(sum, res);
        return res/k;
    }