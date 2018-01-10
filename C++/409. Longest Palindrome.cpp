/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.
*/

/*
算法思想：首先遍历一遍字符串，使用map记录每个字母出现的次数，其key是字母，value是出现的次数，然后遍历map，判断其value值是否为偶数，如果为偶数，说明可以组成回文，所以应该将其加上，如果为奇数的话，应该至少加上其减1（并置flag为1，此flag记录的是可能少加了一个）。
最后判断长度的总数为奇数还是偶数，如果为偶数且flag为1的话，表示还可以加一个字符，否则不能。
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        int ans = 0,flag = 0;
        map<char,int> m;
        for(int i = 0;i < len;i++)
        {
            m[s[i]]++;		//记录字符串中每个字符出现的次数
        }
        
        for(map<char,int>::iterator it = m.begin();it != m.end();it++)
        {
            if(!((*it).second % 2))		//如果该字符出现的次数为偶数，则加上
            {
                ans += (*it).second;
            }
             else if((*it).second > 1)   //如果该字符为奇数，表示至少可以加上其减1，这样肯定可以拼成回文
             {
                 ans +=  (*it).second - 1;
                 flag = 1;
             }
            else
            {
                 flag = 1;
            }
        }
        if(flag && !(ans%2))			//判断是否需要加1
        {
            ans++;
        }
        return ans;
    }
};


/*
discuess：使用哈希集合来存放字符，如果当前存在该字符，则说明集合中的字符可以与当前字符相对称count++,并将集合中的元素删除，如果集合中不存在当前元素，则将其放入集合中。循环遍历字符串完后，判断集合是否为空，如果为空返回2*count（count表示一对字符），如果不为空，则表示还可以加一个字符，返回2*count + 1.
*/

public int longestPalindrome(String s) {
        if(s==null || s.length()==0) return 0;
        HashSet<Character> hs = new HashSet<Character>();
        int count = 0;
        for(int i=0; i<s.length(); i++){
            if(hs.contains(s.charAt(i))){
                hs.remove(s.charAt(i));
                count++;
            }else{
                hs.add(s.charAt(i));
            }
        }
        if(!hs.isEmpty()) return count*2+1;
        return count*2;
}

