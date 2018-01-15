/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
	1.You may use one character in the keyboard more than once.
	2.You may assume the input string will only contain letters of alphabet.
*/

/*
算法思想：使用vector<vector<char>>二维数组来存放键盘字符，遍历字符串字符，判断出当前字符串的第一个字符是属于哪一列的，然后判断剩余字符是否属于该列，如果是，则将该字符串放入结果数组中，否则继续遍历下一个字符串。
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string word;
        int flag,j;
        vector<vector<char>> vec{{'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'},{'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'},{'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'}};
        for(int i = 0;i < words.size();i++)
        {
            if(words[i].length() > 0)
            {
                if(find(vec[0].begin(),vec[0].end(),words[i][0]) != vec[0].end())
                {
                    flag = 0;
                }
                else if(find(vec[1].begin(),vec[1].end(),words[i][0]) != vec[1].end())
                {
                    flag = 1;
                }
                else
                {
                    flag = 2;
                }
                for(j = 1;j < words[i].size();j++)
                {
                    if(flag == 0 && find(vec[0].begin(),vec[0].end(),words[i][j]) == vec[0].end())
                    {
                        break;
                    }
                    else if(flag == 1 && find(vec[1].begin(),vec[1].end(),words[i][j]) == vec[1].end())
                    {
                        break;
                    }
                    else if(flag == 2 && find(vec[2].begin(),vec[2].end(),words[i][j]) == vec[2].end())
                    {
                        break;
                    }

                }
                if(j >= words[i].size())
                    ans.push_back(words[i]);
            }
            else
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};