/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
	Input: [1,3,2,2,5,2,3,7]
	Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

/*
算法思想：可以使用unordered_map来记录每个数据的出现的次数，然后遍历unordered_map，查找符合条件的数据，返回其个数的最大值。
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int num1 =  0,num2 = 0,ans = 0,sz = nums.size();
        unordered_map<int,int> um;
        if(sz < 1)
            return sz;
        for(int i = 0;i < sz;i++)
        {
            um[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        for(it = um.begin();it != um.end();it++)
        {
            cout<<(*it).first<<" "<<um[(*it).first]<<endl;
            if(um.find((*it).first + 1) != um.end())
                num1 = um[(*it).first] + um[(*it).first + 1];
            if(um.find((*it).first - 1) != um.end())
                num2 = um[(*it).first] + um[(*it).first - 1];
            ans = max(ans,max(num1,num2));
        }
        return ans;
    }
};

/*
discuss：
1.run time O(n) space O(n) use unordered_map
First loop through all elements and count each number appearance. Then loop through unordered_map, to find if the key - 1 is in the unordered map. If key - 1 and key both in the map, update the result

2.O(nlogn) running time ,space O(1) using sort
The idea is to loop through each elements and update the result. The start position is used for counting purpose and new start is used for whenever come across different number
When the number is different from previous number, update the new start position. When difference between current position and start position is bigger than 1 then update start position.
*/

//方法1：
int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i: nums)
            m[i]++;
        int res = 0;
        for(auto it:m)
            if(m.count(it.first-1)>0)
                res = max(res, it.second+m[it.first-1]);
        return res;
	}
	
//方法2：
int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = 0;
        for(int i = 1, start = 0, new_start = 0; i<nums.size(); i++)
        {

            if (nums[i] - nums[start] > 1)    
                start = new_start;
            if (nums[i] != nums[i-1]) 
                new_start = i;
            if(nums[i] - nums[start] == 1)
                len = max(len, i-start+1);
        }
        return len;
}
