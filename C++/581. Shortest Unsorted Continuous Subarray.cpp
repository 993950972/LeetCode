/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
	Input: [2, 6, 4, 8, 10, 9, 15]
	Output: 5
	Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
	1.Then length of the input array is in range [1, 10,000].
	2.The input array may contain duplicates, so ascending order here means <=.
*/

/*
算法思想；先备份nums给numsbak，然后直接对nums数组进行排序，遍历numsbak，判断从开始位置和从结束位置有多少元素是与numsbak连续相同的。然后直接用总长度减去相同长度和即可得到需要排序的长度。
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return 0;
        int ans = sz,flag1 = 0,flag2 = 0;
        vector<int> numsbak = nums;
        sort(nums.begin(),nums.end());
        if(numsbak == nums)
            return 0;
        for(int i = 0,j = sz - 1;i <= j;)
        {
            if(!flag1 && nums[i] == numsbak[i])
            {
                ans--;
                i++;
                cout<<ans<<" ";
            }
            else if(nums[i] != numsbak[i])
            {
                flag1 =1;
            }
            if(!flag2 && nums[j] == numsbak[j])
            {
                ans--;
                j--;
                cout<<ans<<" ";
            }
            else if(nums[j] != numsbak[j])
            {
                flag2 = 1;
            }
            cout<<endl;
            if(flag1 && flag2)
                return ans;
        }
        if(ans < 0)
            return 0;
        return ans;
    }
};

/*
discuss：使用一次循环O(n)时间复杂度和O(1)空间。
直接循环一遍找出其右边界和左边界，然后让边界值相减加1即可。
Awesome!
Some explanations:
endIdx = The most right element having greater elements on the left side.
begIdx = The most left element having smaller elements on the right side.
Prove it is effective:
According to the definition, we can know that all elements on the right side of endIdx do not have greater elements on the left side and all elements on the left side of the begIdx do not have greater elements on the right side. Therefore, these two parts are good and we only need to sort the elements between begIdx and endIdx.
Prove the bounds are tight:
According to the definition, the two elements at begIdx and endIdx are “illegal”, so the range to be sort should at least include these two elements.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        int end = -2,beg = -1,maxnum = nums[0],minnum = nums[sz - 1];
        for(int i = 1;i < sz;i++)
        {
            maxnum = max(maxnum,nums[i]);
            minnum = min(minnum,nums[sz - 1 - i]);
            if(nums[i] < maxnum) end = i;
            if(nums[sz - 1 - i] > minnum) beg = sz - 1 - i;
        }
        return end - beg + 1;
    }
};