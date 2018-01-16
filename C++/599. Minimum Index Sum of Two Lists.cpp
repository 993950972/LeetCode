/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
	1.The length of both lists will be in the range of [1, 1000].
	2.The length of strings in both lists will be in the range of [1, 30].
	3.The index is starting from 0 to the list length minus 1.
	4.No duplicates in both lists.
*/

/*
算法思想：要减少时间复杂度，可以使用unordered_map（底层使用hash表来实现，故查找时间复杂度为O(1)）来记录list2每个单词的位置，key为单词，value为key所在的位置。然后遍历list2，根据unordered_map来查找list1中是否也有此单词，如果有，则判断两者位置和是否最小，如果最小，则将前结果集置空，放入该字符串，如果相等，则直接放入结果集中，否则，继续下一个元素进行判断。
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> um;
        vector<string> ans;
        int sz1 = list1.size(),sz2 = list2.size();
        for(int i = 0;i < sz2;i++)
        {
            um[list2[i]] = i;
        }
        int min = INT_MAX;
        for(int i = 0;i < sz1;i++)
        {
            if(um.count(list1[i]) > 0 && ((i + um[list1[i]]) < min))
            {
                ans.clear();
                min = i + um[list1[i]];
                ans.push_back(list1[i]);
            }
            else if(um.count(list1[i]) > 0 && ((i + um[list1[i]]) == min))
            {
                ans.push_back(list1[i]);
            }
        }
        return ans;
    }
};