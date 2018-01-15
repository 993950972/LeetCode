/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
	1.The string consists of lower English letters only.
	2.Length of the given string and k will in the range [1, 10000]

*/

/*
算法思想：调用reverse函数和使用字符串的迭代器来进行相应的操作。
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int cnt = 0,a = 2*k;
        auto it = s.begin();
        while(len >=  a)
        {
            cnt += a;
            reverse(it,it + k);
            len -= a;
            it += a;
        }
        if(len >= k)
        {
            reverse(it,it+k);
        }
        else
        {
            reverse(it,s.end());
        }
        return s;
    }
};

/*
discuss:直接遍历一遍字符串，将相应字符调换swap函数
*/
class Solution {
public:
    /**
     * 0            k           2k          3k
     * |-----------|-----------|-----------|---
     * +--reverse--+           +--reverse--+
     */
    string reverseStr(string s, int k) {
        for (int left = 0; left < s.size(); left += 2 * k) {
            for (int i = left, j = min(left + k - 1, (int)s.size() - 1); i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};