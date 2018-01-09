/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

/*
算法思想：双射一一对应，考虑使用C++ STL中的map来解决。将两个string中的字符和单词分别对应于数字，如果当前元素已经有对应值，则判断对应值是否相等，若不等，则返回false，否则，返回true。
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len1,len2,pos;
        len1 = pattern.length();
        len2 = str.length();
        vector<string> words;
        string tmp;
        pos = 0;
		//将str中的单词拆开，放入words中。
        for(int i = 0;i < len2;i++)
        {
            if(str[i] == ' ')
            {
                tmp = str.substr(pos,i - pos);
                words.push_back(tmp);
                pos = i + 1;
            }
        }
        tmp = str.substr(pos,len2 - pos);
        words.push_back(tmp);
        if(len1 != words.size())
            return false;
        map<char,int> m1;
        map<string,int> m2;
		//使用map去映射
        for(int i = 0;i < len1;i++)
        {
            if(m1.find(pattern[i]) == m1.end())
            {
                m1[pattern[i]] = i;
            }
            if(m2.find(words[i]) == m2.end())
            {
                m2[words[i]] = i;
            }
            if(m1.find(pattern[i]) != m1.end() && m2.find(words[i]) != m2.end() && m1[pattern[i]] != m2[words[i]])
            {
                return false;
            }
        }
        return true;
    }
};

/*
discuss:看了discuss之后，发现原来拆单词还有一种很简单的方法，可以使用isstringstream流。
算法思想:也是将其映射到相同的第三方，然后考察映射值是否相等，如果不等，则返回false，否则，返回true。
*/
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}