/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
	Input: [1,2,3]
	Output: 6
Example 2:
	Input: [1,2,3,4]
	Output: 24
Note:
	1.The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
	2.Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

*/

/*
算法思想：直接排序，三个数乘积最大的可能在前两个数乘积与最后一个数的乘积或者最后三个数的乘积。
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans;
        int sz = nums.size();
        if(sz == 3)
            return nums[0] * nums[1] * nums[2];
        sort(nums.begin(),nums.end());
        int num1,num2;
        num1 = nums[0] * nums[1] * nums[sz - 1];
        num2 = nums[sz - 1] * nums[sz - 2] * nums[sz - 3];
        if(num1 > num2)
            return num1;
        return num2;
    }
};

/*
discuss：因为乘积最大值只可能是：1三个最大数相乘；2.两个最小数与最大数相乘。
故只需要一遍循环就能找出这些数，然后返回1、2中的较大值。
*/
  public int maximumProduct(int[] nums) {
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }

            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        return Math.max(max1*max2*max3, max1*min1*min2);
    }