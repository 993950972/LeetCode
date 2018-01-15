/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

/*
算法思想：遍历字符串，遇到空格且flag为1，调用reverse函数翻转字符串。
*/

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int flag = 0;
        if(len < 2)
            return s;
        auto it = s.begin();
        for(int i = 0;i < len;i++)
        {
            if(flag)                //如果flag为1，说明前面是非空字符
            {
                if(s[i] == ' ')     //如果遇到空格，则翻转字符串，并将flag设为0
                {
                    reverse(it,s.begin() + i);
                    flag = 0;
                }
            }
            else                    //如果flag为0，且当前字符为非空格字符，将flag置位1，并重置it迭代器
            {
                if(s[i] != ' ')
                {
                    flag = 1;
                    it = s.begin() + i;
                }
            }
        }
        if(s[len - 1] != ' ')
            reverse(it,s.end());
        return s;
    }
};

/*
discuss：
*/

class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) { } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        
        return s;
    }
};