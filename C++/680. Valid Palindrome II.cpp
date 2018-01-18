/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
	Input: "aba"
	Output: True
Example 2:
	Input: "abca"
	Output: True
	Explanation: You could delete the character 'c'.
Note:
	1.The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/

/*
算法思想：使用i，j指着分别指向字符串的首字符和尾字符，然后循环遍历，查看i指向的字符是否等于j指向的字符，如果相等，则i向右移动，j向左移动，如果不相等，则判断s[i] == s[j - 1]?或者s[i + 1] == s[j]?如果有一个相等，则分别判断删除s[i],s[j]是否为回文。
*/

class Solution {
public:
    bool isPalindrome(string s)
    {
        int i = 0,j = s.length() -1;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int len = s.length();
        int i = 0,j = len - 1,cnt = 0;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                cnt++;
                if(s[i] == s[j - 1] || s[i + 1] == s[j])
                {
                    return (isPalindrome(s.substr(i,j - i)) || isPalindrome(s.substr(i + 1,j - i)));
                }
                else
                    return false;
            }
        }
        return cnt < 2;
    }
};

/*
discuss：算法思想相同。都用两指针分别向中间移动，如果不等，则判断删除一个字符是否为回文。
*/

public boolean validPalindrome(String s) {
    int l = -1, r = s.length();
    while (++l < --r) 
        if (s.charAt(l) != s.charAt(r)) return isPalindromic(s, l, r+1) || isPalindromic(s, l-1, r);
    return true;
}

public boolean isPalindromic(String s, int l, int r) {
    while (++l < --r) 
        if (s.charAt(l) != s.charAt(r)) return false;
    return true;
}