/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
	Input: [1, 2, 2, 3, 1]
	Output: 2
	Explanation: 
	The input array has a degree of 2 because both elements 1 and 2 appear twice.
	Of the subarrays that have the same degree:
	[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
	The shortest length is 2. So return 2.
Example 2:
	Input: [1,2,2,3,1,4,2]
	Output: 6
Note:

	nums.length will be between 1 and 50,000.
	nums[i] will be an integer between 0 and 49,999.
*/

/*
算法思想：首先要找出众数是哪些和他们的位置分别在哪，众数与其位置的对应关系很容易想到可以使用hash map（C++中的unordered_map）来实现，其key记录的是元素值，value是数组中key的对应位置。
刚开始写的时候使用unordered_map来记录，key是数组中元素值，value记录的是其出现的次数。找到众数，判断其数组长度是否最小，返回其中最小值。这样写的过程也想到上述简洁方法。
hash table很重要！！！
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> um;
        vector<int> vec;
        int sz = nums.size();
        for(int i = 0;i < sz;i++)
        {
            um[nums[i]].push_back(i);
        }
        int shortest = 0;
        for(unordered_map<int,vector<int>>::iterator it = um.begin();it != um.end();it++)
        {
            shortest = max(shortest,(int)(*it).second.size());
        }
        int ans = nums.size();
        for(unordered_map<int,vector<int>>::iterator it = um.begin();it != um.end();it++)
        {
            if((*it).second.size() == shortest)
            {
                ans = min(ans,(*it).second.back() - ((*it).second)[0] + 1);
            }
        }
        return ans;
    }
};

/*
discuss：使用两个map，第一个map记录每个元素出现的次数，其key为元素值，value为该key在数组中出现的次数，第二个map记录的是元素key的起始出现的位置和末尾出现的位置。
这样根据两个map就可以求出其最小连续子数组长度了。
1.Get degree of array, frequency of all integers in array, and the indices of the first and last occurrence of each integer in the array
2.Return the minimum occurrence range of each integer which appears degree number of times in the array,
*/

public int findShortestSubArray(int[] nums) {
    int degree = 0, n = nums.length, minSize = n;
    Map<Integer, Integer> map = new HashMap<>();
    Map<Integer, Integer[]> map2 = new HashMap<>();
    
    for (int i=0;i<n;i++) {
        map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        degree = Math.max(degree, map.get(nums[i]));

        if (map2.get(nums[i]) == null) map2.put(nums[i], new Integer[2]);
        Integer[] numRange = map2.get(nums[i]);
        if (numRange[0] == null) numRange[0] = i;
        numRange[1] = i;
    }

    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        if (entry.getValue() != degree) continue;
        Integer[] range = map2.get(entry.getKey());
        minSize = Math.min(minSize, range[1] - range[0] + 1);  
    }
    return minSize;
}
