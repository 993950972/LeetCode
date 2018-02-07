/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
	Input: nums = [10, 5, 2, 6], k = 100
	Output: 8
	Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

	0 < nums.length <= 50000.
	0 < nums[i] < 1000.
	0 <= k < 10^6.
*/

/*
算法思想：贪心法，判断当前乘积是否小于k，如果小于则继续乘以当前元素，并且i++移动指针i，如果当前乘积大于k，开始计算m，n，如果flag为1，说明ans需要更新，之后更新i，j即可。
如：10,5,2,6,5
1） n = 0,m = 2
2） n = 1,m = 2
3） n = 2,m = 1
根据公式：ans += n * m + (1 + m) * m / 2;即可以算出答案。
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0,j = 0,l = 0,flag = 0;
        int sz = nums.size();
        long long ans = 0,temp = 1,n = 0,m = 0;
        while(i <= sz)
        {
            if(temp < k)
            {
                temp *= nums[i];
                i++;
                flag = 1;
            }
            else if(i <= sz)
            {
                n = l - j;
                if(n < 0)
                    n = 0;
                m = i - l - 1;
                if(m < 0)
                    m = 0;
                if(flag)
                {
                    ans += n * m + (1 + m) * m / 2;
                    flag = 0;
                    l = i - 1;
                }
                if(i > 0 && nums[i - 1] < k)
                {
                    temp /= nums[j];
                    j++;
                }
                else
                {
                    if(i < sz)            
                    {
                        temp = nums[i];
                        j = i;
                        l = i;
                    }
                    i++;
                }
            }
        }
        if(flag)
        {
            n = l - j;
            if(n < 0)
                n = 0;
            m = i - l - 1 ;
            if(m < 0)
                m = 0;
            ans += n * m + (1 + m) * m / 2;
        }
        return ans;
    }
};

/*
discuss: 贪心法。
Here are two solutions with similar ideas.

For nums[i], count range [left, i], whose product is just < k
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), prod = 1, ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k) prod /= nums[left++];
            ans += i - left + 1;
        }
        return ans;
    }
};
/*
For nums[i], count range [i, j)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, prod = 1, j = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && i <= j) 
                prod =  prod/nums[i-1];
            else 
                j = i;
            while (j < n &&  prod*nums[j] < k) prod *= nums[j++];
            ans += j-i;
        }
        return ans;
    }
};