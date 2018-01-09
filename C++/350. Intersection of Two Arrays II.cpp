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
��������һ����ȥ�Ƚϣ����ƥ��ɹ���������2��Ԫ�ر����Ϊfalse����ʾ�Ѿ��ɹ�ƥ�䣩����������������С�
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
	ʱ�临�Ӷȵ͵Ľⷨ��ʹ��C++ STL�е�map���ݽṹ�������ѭ������һ������1��ʹ��map��value����¼���Ӧkey
	������1�г��ֵĴ�����Ȼ��ѭ����������2���ж�map��key��Ӧ��value�Ƿ����0���������0�����ʾ����1��Ҳ�и�Ԫ�أ�
	�ʽ���Ԫ�ط��������У�ͬʱ��valueֵ��1.
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

