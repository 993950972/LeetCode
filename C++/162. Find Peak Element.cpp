/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
*/

/*
算法思想：循环遍历一次，直接判断该元素是否大于两边的元素，如果该元素是边界元素，直接判断是否大于其左边或者右边的元素。
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
            return 0;
        for(int i = 0;i < sz;i++)
        {
            if((i > 0 && i < sz - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) || (i == 0 && nums[i] > nums[i + 1]) || (i == sz - 1 && nums[i] > nums[i - 1]))
            {
                return i;
            }
        }
        return -1;
    }
};

/*
discuss：Consider that each local maximum is one valid peak.
My solution is to find one local maximum with binary search.
Binary search satisfies the O(logn) computational complexity.

Binary Search: recursion
*/

class Solution {
public:

int findPeakElement(const vector<int> &num) {
    return Helper(num, 0, num.size()-1);
}
int Helper(const vector<int> &num, int low, int high)
{
    if(low == high)
        return low;
    else
    {
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        if(num[mid1] > num[mid2])
            return Helper(num, low, mid1);
        else
            return Helper(num, mid2, high);
    }
}
};


class Solution {
public:

int findPeakElement(const vector<int> &num) {
    return Helper(num, 0, num.size()-1);
}
int Helper(const vector<int> &num, int low, int high)
{
    if(low == high)
        return low;
    else
    {
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        if(num[mid1] > num[mid2])
            return Helper(num, low, mid1);
        else
            return Helper(num, mid2, high);
    }
}
};