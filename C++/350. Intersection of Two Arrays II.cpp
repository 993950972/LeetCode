/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
蛮力法，一个个去比较，如果匹配成功，则将数组2中元素标记设为false（表示已经成功匹配），并将其放入结果集中。
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int sz1,sz2;
        sz1 = nums1.size();
        sz2 = nums2.size();
        vector<bool> mark(sz2,true);
        for(int i = 0;i < sz1;i++)
        {
            for(int j = 0;j < sz2;j++)
            {
                if(mark[j] && nums1[i] == nums2[j])
                {
                    ans.push_back(nums2[j]);
                    mark[j] = false;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
	时间复杂度低的解法：使用C++ STL中的map数据结构来解决。循环遍历一遍数组1，使用map的value来记录其对应key
	在数组1中出现的次数，然后循环遍历数组2，判断map中key对应的value是否大于0，如果大于0，则表示数组1中也有该元素，
	故将该元素放入结果集中，同时将value值减1.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};

