/*
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 
Note:

	1.Both strings' lengths will not exceed 100.
	2.Only letters from a ~ z will appear in input strings.
*/

/*
算法思想：空字串和字符串本身都是该字符串的子串，要求最长的非公共子串很简单，返回两个字符串中最长的那个就可以，因为最长的那个字符串肯定是另一个的非公共子字符串，如果两个字符串相同，说明没有非公共子字符串，故返回-1.

1.I first considered the special case, two strings are not of same length, it is clearly the longest one is the answer.
2.Then for two strings with same length, if anyone of them has a char which the other string does not have, clearly the whole string’s length is the answer.
3.Then for two strings with same charset, one string is just a combination of chars of another string, I thought about the ordering of chars matters here. Then I got it, if they are not equal, we can quickly decide, which also covers case 2).
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
       if(a == b) 
           return -1;
        int a_len = a.length();
        int b_len = b.length();
        return a_len>b_len?a_len:b_len;
    }
};