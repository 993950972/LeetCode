/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

/*
算法思想：这道题要求的是字符串中段的数量，段是以空格分开的。设一个标志位，用来表示这个段是否已经统计过了，循环遍历字符串，如果段未统计过且当前字符为非空字符，则段数加1，且设置标记位，表示该段已经统计过，如果当前字符为空，则清空标记位。
*/

class Solution {
public:
    int countSegments(string s) {
        int ans = 0,flag = 1;
        int len = s.length();
        if(!len)
            return 0;
        for(int i = 0;i < len;i++)
        {
            if(flag && s[i] != ' ')
            {
                ans++;
                flag = 0;
            }
            if(s[i] == ' ')
            {
                flag = 1;
            }
        }
        return ans;
    }
};


/*
discuess：这是一种非常常见的统计方法，首先在字符串末尾添加一个分解符（空字符）。然后循环遍历字符串，若当前字符为空且其上一个字符不为空，则说明当前字符处于一个新段中，段数加1.循环完毕，返回段数。
*/

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        s.push_back(' ');
        for(int i = 1; i < s.size(); ++i)
          if(s[i] == ' ' && s[i-1] != ' ') ++res;
        return res;
    }
};