/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

/*
算法思想：可以使用set集合来，C++ STL中的set数据结构的底层实现就是红黑树，所以set集合中的元素是有序存放的，故当set的size大于3时，只需要将set.begin()元素删除即可。最后判断set的大小是否等于3，如果等于3，则返回(*)set.begin()，否则，返回(*)set.rbegin().
set数据结构很重要！！！
*/
class Solution {
public:
    
    int thirdMax(vector<int>& nums) {
       set<int> top3;
        for(int num:nums)
        {
            top3.insert(num);
            if(top3.size() > 3)
                top3.erase(top3.begin());
        }
        if(top3.size() == 3) 
            return *(top3.begin());
        return *(top3.rbegin());
        
    }
};