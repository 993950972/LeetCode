/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

/*
算法设计：考虑字符串要由子字符串组成，其长度就必须是子字符串长度的整数倍，故先将所有因数求出并放入vector中，包括1但不包括本身（因为字符可以有多个一样字符组成）。然后循环遍历存放因数的vector，取长度为vec[i]的子串，判断原字符串是否可以由其组成，如果可以返回true，否则循环完毕，返回false。
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        vector<int> vec;
        if(len < 2)
            return false;
        char ch = s[0];
        for(int i = 1;i <= len/2;i++)       
        {
            if(!(len%i))
                vec.push_back(i);
        }
        for(int i = vec.size() - 1;i >= 0;i--)
        {
            int num = len/vec[i];
            string sub = s.substr(0,vec[i]);
            string str;
            while(num--)
            {
                str+=sub;
            }
            if(s == str)
                return true;
        }
        return false;
        
    }
};

/*
discuss：
1.Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
2.Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
3.To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide (str.size()-last entry).
*/

  bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }