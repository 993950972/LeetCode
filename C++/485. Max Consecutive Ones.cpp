/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

/*
算法思想：遍历一次，max记录的是截止到当前位置连续1的个数，cnt记录的是从上一个0开始到当前位置连续1的个数。如果当前位置为0，判断max是否大于cnt，如果max小于cnt，则更新max，且置cnt为0，如果max大于cnt，则只需要重置cnt为0即可。
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0,max= 0;
        int len = nums.size();
        for(int i = 0;i < len;i++)
        {
            if(nums[i])
            {
                cnt++;
            }
            else if(cnt > max)
            {
                max = cnt;
                cnt = 0;
            }
            else
            {
                cnt = 0;
            }
        }
        if(cnt > max)
            max = cnt;
        return max;
    }
};