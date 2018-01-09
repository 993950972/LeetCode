/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
算法思想：循环遍历容器，判断当前元素是否为0，如果不为0，则赋值给nums[j]，否则记录0的个数，循环完毕，只需在nums末尾添加0即可。
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,cnt = 0,j = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i])
            {
                nums[j++] = nums[i];
            }
            else
            {
                cnt++;
            }
        }
        while(cnt--)
        {
            nums[j++] = 0;
        }
    }
};