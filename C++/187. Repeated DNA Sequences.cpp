/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

	Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

	Return:
	["AAAAACCCCC", "CCCCCAAAAA"].
*/

/*
算法思想：使用hash table来记录每个长度为LENGTH的相同单词的个数，然后循环遍历hash table将其value大于1的key放入vector中。
*/

class Solution {
public:
   #define LENGTH 10
    vector<string> findRepeatedDnaSequences(string s) {  
        int len = s.length();
        vector<string> ans;
        unordered_map<string,int> um;
        if(len <= LENGTH)
            return ans;
        for(int i = 0;i <= len - LENGTH;i++)
        {
            um[s.substr(i,LENGTH)]++;
        }
        for(unordered_map<string,int>::iterator it = um.begin();it != um.end();it++)
        {
            if((*it).second >= 2)
                ans.push_back((*it).first);
        }
        return ans;
    }
};