/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
	The length of A and B will be between 1 and 10000.
*/

/*
算法思想：可以修改字符串查找方法，当查找到A的末尾时并不结束，继续循环遍历查找A，直至B完全匹配，或者匹配到A[i] != B[j]，则大循环i++，直至以A字符串遍历完毕，B都存在不相等的情况，故不能匹配成功，放回-1.
This is basically a modified version of string find, which does not stop at the end of A, but continue matching by looping through A.
*/

int repeatedStringMatch(string A, string B) {
    for (auto i = 0, j = 0; i < A.size(); ++i) {
        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
        if (j == B.size()) return (i + j) / A.size() + ((i + j) % A.size() != 0 ? 1 : 0);
    }
    return -1;
}

/*
discuss：
方法1：改进上面匹配方法，使用KMP来解决。
ses a prefix table (KMP). We first compute the prefix table using the suffix and prefix pointers. Then we are going through A only once, shifting B using the prefix table.

This solution requires O(n) extra memory for the prefix table, but it’s the fastest out there (OJ runtime is 3 ms). However, we do not need extra memory to append A multiple times, as in many other solutions.

Also thanks to @mylzsd for the review and the optimization to move i faster (skip multiple search characters) rather incrementing it one by one.

方法2：在确保多个A之后，B肯定是其子串的情况下，循环遍历A与B，直至B匹配成功。
*/

//方法一：改进匹配方法，使用KMP表来循环遍历。
int repeatedStringMatch(string a, string b) {
    vector<int> prefTable(b.size() + 1); // 1-based to avoid extra checks.
    for (auto sp = 1, pp = 0; sp < b.size(); prefTable[++sp] = pp) {
        pp = b[pp] == b[sp] ? pp + 1 :  prefTable[pp];
    }
    for (auto i = 0, j = 0; i < a.size(); i += max(1, j - prefTable[j]), j = prefTable[j]) {
        while (j < b.size() && a[(i + j) % a.size()] == b[j]) ++j;
        if (j == b.size()) return (i + j) / a.size() + ((i + j) % a.size() != 0 ? 1 : 0);
    }
    return -1;
}

//方法2：修改字符串查找方法。
class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    string tmp = A + A;
    size_t pos = tmp.find(B.substr(0, A.size()));
    if(pos == string::npos)
      return -1;

    int count = 1;
    size_t i = 0;
    while(i < B.size()) {
      if(pos == A.size()) {
	pos = 0;
	++count;
      }
      if(A[pos++] != B[i++])
	return -1;
    }

    return count;
  }
};