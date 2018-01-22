/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
算法思想：直接循环遍历一遍，找出最小元素即可。
当然也可以使用二分法，因为两部分元素都是有序的，故使用二分查找方法比较好。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int min_num = INT_MAX;
        for(int i = 0;i < sz;i++)
        {
            if(min_num > nums[i])
                min_num = nums[i];
        }
        return min_num;
    }
};

/*
discuss：Classic binary search problem.

Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array. So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element. If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.

Welcome to put your comments and suggestions.
*/

 int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }