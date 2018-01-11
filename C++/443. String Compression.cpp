/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
*/

/*
算法思想：刚开始理解错了题意，没仔细看题忽略了in-place。重写了下。思想：循环遍历vector，统计字符个数，如果字符个数大于1，则将该字符和其个数（转换成字符）放入vector(ans)中。如果等于1，则只需要将该字符放入ans中即可。遍历完毕，判断最后cnt值是否大于1，大于则将其转换成字符串并放入ans中 。
*/

class Solution {
public:
   
    string numToStr(int num)
    {
        string str;
        while(num)
        {
            str += (num % 10) + '0';
            num/=10;
        }
        return str;
    }    
    int compress(vector<char>& chars) {
        int sz = chars.size();
        if(sz < 2)
            return chars.size();
        char temp = chars[0];
        int cnt = 1;
        vector<char> ans;
        ans.push_back(temp);
        for(int i = 1;i < sz;i++)
        {
            if(chars[i] == temp)
            {
                cnt++;				//统计连续相同字符的个数
            }
            else					//如果相邻字符不等
            {
                if(cnt > 1)			//且cnt>1，则将数字转换成字符填入ans中
                {
                    string str = numToStr(cnt);
                    for(int j = str.size() - 1;j >= 0;j--)
                    {
                        ans.push_back(str[j]);
                    }
                }					//更新为temp为当前字符，更新计数器。
                temp = chars[i];
                cnt = 1;
                ans.push_back(temp);
            }
        }
        if(cnt > 1)
        {
            string str = numToStr(cnt);
            for(int j = str.size() - 1;j >= 0;j--)
            {
                ans.push_back(str[j]);
            }
        }
        chars = ans;
        return ans.size();
    }
};