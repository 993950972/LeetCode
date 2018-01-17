/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
	Input: nums = [1,2,2,4]
	Output: [2,3]
Note:
	1.The given array size will in the range [2, 10000].
	2.The given array's numbers won't have any order.

*/

/*
算法思想：使用unordered_map来记录数组中各个元素的个数，然后遍历从1到nums.size()，查找其元素的个数，判断是否大于1或者不存在，如果是，放入结果集中，否则继续查询下一个元素的个数。最后需要注意的是，返回结果集需要调整ans[0]、ans[1]的位置。
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> um;
        int sz = nums.size();
        for(int i = 0;i < sz;i++)
        {
            um[nums[i]]++;
        }
        for(int i = 1;i <= sz;i++)
        {
            if(um.find(i) == um.end() || um[i] > 1)
            {
                ans.push_back(i);
            }
        }
        if(um[ans[1]] > 1)
            swap(ans[0],ans[1]);
        return ans;
    }
};

/*
discuss。空间使用较少，值得借鉴。
*/
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] res = new int[2]; // duplicate, missing
        //For each number we found, set nums[number-1] to its negative value (<0)
        for(int i=0; i<nums.length; i++) {
            int idx = Math.abs(nums[i])-1; //since index starts from 0, and the set starts from 1
            if(nums[idx]> 0) nums[idx] = -nums[idx];
            else res[0] = idx+1; //have already been found
        }
        // At this point, only nums[missingNumber-1] > 0
        for(int i=0; i<nums.length; i++) {
            if(nums[i] <0) nums[i] = -nums[i]; //restore the original values
            else res[1]=i+1;//since index starts from 0, and the set starts from 1
        }
        return res;
    }
}