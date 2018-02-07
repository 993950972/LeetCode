/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1.	1 <= len(start) = len(end) <= 10000.
2.	Both start and end will only consist of characters in {'L', 'R', 'X'}.
*/

/*
算法思想：使用贪心法，加回溯。每次遇到不能匹配的就去寻找可以交换的对，如果存在可以交换的则交换，否则返回false；交换后则回溯到当前比较的元素，继续下一次比较，如果比较完毕，返回true。
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        if(start == end)
            return true;
        int len1,len2,i,j;
        len1 = start.length(),len2 = end.length();
        if(len1 != len2)
            return false;
        for(i = 0;i < len1;i++)
        {
            if(start[i] != end[i])       //如果不等，则查找是否存在可以交换的对，否则返回false。
            {
                for(j = i;j < len1 - 1;j++)
                {
                    if((start[j] == 'X' && start[j + 1] == 'L') || (start[j] == 'R' && start[j + 1] == 'X'))
                    {
                        swap(start[j],start[j + 1]);
                        break;
                    }
                }
                if(j >= len1 - 1)
                    return false;
                i--;       //回溯
            }
        }
        return true;
    }
};

