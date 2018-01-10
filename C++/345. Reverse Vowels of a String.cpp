/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

/*
算法思想：可以直接循环遍历一遍将所有的元音字符放入vector容器中，然后再遍历一遍，然后将原来所有的元音字母替换为逆序的元音字母。
*/

class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        vector<char> vec;
        for(int i = 0;i < len;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vec.push_back(s[i]);
            }
        }
        int sz = vec.size();
        for(int i = 0;i < len;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = vec[--sz];
            }
        } 
        return s;
    }
};

/*
discuess:代码更加简洁，其用到了字符串的两个函数：find_first_of(string str,int index),find_last_of(string str,int index).这样i从前面扫描，j从后面开始扫描，这样就可以找到对应的元音字符，然后进行交换即可。
*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

