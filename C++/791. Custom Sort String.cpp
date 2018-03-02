/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
*/

/*
算法思想：使用统计法，首先统计字符串T的各个字符的个数，然后循环遍历字符串S，判断计数器数组中是否大于0，如果大于0，则说明S中的当前字符在T中，将其拼接，并更新计数数组，继续判断计数数组是否大于0，如果大于0，则说明有当前字符有相同字符，则继续拼接当前字符，并更新计数数组。最后将在T中字符且不在S中字符进行拼接即可。
返回拼接后的字符串。
*/

class Solution {
public:
    string customSortString(string S, string T) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        string ans;
        for(auto it : T)            //统计T中各个字符个数
        {
            cnt[it -  'a']++;
        }
        for(auto it : S)            //按S字符串中字符顺序，给T排序（排序的是既在S中又在T中的字符）
        {
            while(cnt[it - 'a']-- > 0)
                ans += it;
        }
        for(char it = 'a';it <= 'z';it++)//将不在S中但是在T中的字符拼接上（剩余字符拼接上）
        {
            while(cnt[it - 'a']-- > 0)
                ans += it;
        }
        return ans;
    }
};
