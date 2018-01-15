/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
	1.'A' : Absent.
	2.'L' : Late.
	3.'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
	Input: "PPALLP"
	Output: True
Example 2:
	Input: "PPALLL"
	Output: False
*/

/*
算法思想：直接循环一遍，统计'A'的个数和连续'L'的个数。最后判断是否超过1或者2.
*/

class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length();
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < len;i++)
        {
            if(s[i] == 'L')
            {
                cnt2++;
                if(cnt2 > 2)
                    return false;
            }
            else
            {
                cnt2 = 0;
                if(s[i] == 'A')
                {
                    cnt1++;
                    if(cnt1 > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
