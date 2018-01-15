/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
	Input: "USA"
	Output: True
Example 2:
	Input: "FlaG"
	Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

/*
算法思想：如果字符串长度小于2，直接返回true，表示是合法使用。否则判断字符串的第一个字符和第二个字符，分别使用flag0和flag1来记录，然后遍历字符串后面的字符，根据flag0和flag1和当前字符来判断是否合法使用。
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if(len < 2)         //如果长度小于2，返回true，肯定合法。
            return true;
        int flag0,flag1;    //使用flag0、flag1来记录第一个字符、第二个字符的大小写情况
        if(word[0] >= 'A' && word[0] <= 'Z')
            flag0 = 1;
        else
            flag0 = 0;
        if(word[1] >= 'A' && word[1] <= 'Z')
            flag1 = 1;
        else
            flag1 = 0;
        if(!flag0 && flag1)
            return false;
        for(int i = 2;i < len;i++)
        {
            if(flag0 && flag1 && word[i] >= 'a' && word[i] <= 'z')      //如果第一个字符、第二字符大写，后面字符小写，说明不合法，返回false
                return false;
            if(flag0 && !flag1 && word[i] >= 'A' && word[i] <= 'Z')     //如果第一个字符、第二字符小写，后面字符大写，说明不合法，返回false
                return false;
            if(!flag0 && word[i] >= 'A' && word[i] <= 'Z')              //如果第一个小写、后面字符大写，说明不合法，返回false
                return false;
        }
        return true;                                                    //否则合法，返回true。
    }
};

/*
算法思想：循环遍历字符串，统计大写字符的个数，最后判断cnt是否为0或者cnt是否等于字符串的长度，或者判断cnt=1且首字符为大写
*/

public class Solution {
    public boolean detectCapitalUse(String word) {
        int cnt = 0;
        for(char c: word.toCharArray()) if('Z' - c >= 0) cnt++;
        return ((cnt==0 || cnt==word.length()) || (cnt==1 && 'Z' - word.charAt(0)>=0));
    }
}