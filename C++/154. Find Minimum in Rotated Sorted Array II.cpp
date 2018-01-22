/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

/*
算法思想：二分搜索法。当中间元素大于最右侧元素，则更新left为mid + 1；当中间元素大于最左侧元素，则更新right为mid；否则，不能判断最小元素是否在中间元素的左右侧，故r--。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size() - 1,mid;
        while(l < r)
        {
            mid = l + (r - l)/2;
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if(nums[mid] > nums[l])
            {
                r = mid;
            }
            else
            {
                r--;
            }
        }
        return nums[l];
    }
};