/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
	Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
	Return 16
	The two words can be "abcw", "xtfn".

Example 2:
	Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
	Return 4
	The two words can be "ab", "cd".

Example 3:
	Given ["a", "aa", "aaa", "aaaa"]
	Return 0
	No such pair of words.
*/

/*
算法思想：这里最重要的是如何快速判断两个字符是否具有相同字符，我刚开始的解法是循环遍历26个字符，判断这些单词中存在相同字符的有哪些，将其记录下来，但是后来发现虽然记录下来之后，要查找没有相同字符的单词还是比较费劲。
discuss：看了别人答案，发现可以使用一个数来记录一个单词，将1按位左移(ch - 'a')位，ch为单词中的字符，得到的结果与value[i]按位或，这样如果两个单词不存在相同的字符，则其对应的数按位&肯定为0，只需要将所有单词对应的数记录下来即可。
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size(),ans = 0,i = 0;
        vector<int> value(sz);
        for(string word : words)
        {
            for(char ch : word)
            {
                value[i] |= 1 << (ch - 'a');      //使用一个数记录每个单词（字母及顺序）
            }
            i++;
        }
        for(int i = 0;i < sz;i++)
        {
            for(int j = i + 1;j < sz;j++)
            {
                if((value[i] & value[j]) == 0 && words[i].length() * words[j].length() > ans)
                    ans = words[i].length() * words[j].length();
            }
        }
        return ans;
    }
};