/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

/*
算法思想：如果允许改变输入数组的话，可以将数组的每个元素改为存放当前位置之前所有元素的和（包括当前元素）。
即：nums[i] = 原nums[0] + ... + nums[i]。
这样求i~j之间的和就等于nums[j] - nums[i - 1]，当时当i==0时，就等于nums[j]。
这是一种常见的用法，如果有多次调用，可以节省大量的时间。
*/

class NumArray {
public:
    vector<int> nums1;
    NumArray(vector<int> nums) {
        int sz = nums.size();
        for(int i = 1;i < sz;i++)
        {
            nums[i] += nums[i - 1];
        }
        nums1= nums;
    }
    
    int sumRange(int i, int j) {
        if(i > 0)
            return nums1[j] - nums1[i - 1];
        return nums1[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */