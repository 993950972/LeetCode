/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
	Input: [4,2,3]
	Output: True
	Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
	Input: [4,2,1]
	Output: False
	Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/

/*
算法思想：贪心法，遇到nums[i - 1] > nums[i]时，调节的既要符合单调不减要求也要越小越好，这样调节完后，计算出来的调节次数才是最小的。故当nums[i - 1] > nums[i]时，应该调节nums[i - 1]，如果调节nums[i]，这样可能后面调节的次数会增加，但是如果nums[i - 2] > nums[i]时，应该调节调节nums[i - 1]的话，还得再调节nums[i - 2]就不符合条件，故只能调节nums[i].
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3)
            return true;
        int temp = nums[0],cnt = 0;     //cnt统计至少需要改变数字多少次才能使得数组中的数据有序，temp记录的是第i个元素的前一个元素。
        for(int i = 1;i < sz;i++)
        {
            if(temp > nums[i])          //当temp大于nums[i]，说明前面的元素大于后面的元素，需要调整，故cnt++。
            {
                cnt++;
                if(i >= 2 && nums[i - 2] > nums[i])   //当nums[i - 2] > nums[i]且nums[i - 1] > nums[i]时，说明只能讲nums[i]调大，至少调整到nums[i -  1]也即temp，temp大小不需要更新
                {
                    nums[i] = temp;
                }
               else if(i >= 2)                      //当nums[i - 2] <= nums[i]且nums[i - 1] > nums[i]，说明只需要将nums[i - 1]调至[nums[i - 2],nums[i - 1]]之间任何一数即可。
                {
                    nums[i - 1] = nums[i];
                    temp = nums[i];
                }
                else                                //当i == 1且nums[i - 1] > nums[i]只能将nums[i - 1]调至小于等于nums[i]
                {
                    temp = nums[i];
                } 
            }
            else 
                temp = nums[i];
            if(cnt > 1)
                return false;
        }
        return true;
    }
};

/*
discuss：算法思想也是贪心法，与上面类似。
*/

/*
This problem is like a greedy problem. When you find nums[i-1] > nums[i] for some i, you will prefer to change nums[i-1]'s value, since a larger nums[i] will give you more risks that you get inversion errors after position i. But, if you also find nums[i-2] > nums[i], then you have to change nums[i]'s value instead, or else you need to change both of nums[i-2]'s and nums[i-1]'s values.
*/

//Java version:

 public boolean checkPossibility(int[] nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.length && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1; 
    }
//C++ version:

bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 