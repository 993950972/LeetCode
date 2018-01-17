/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
	Input: 5
	Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
	Input: 3
	Output: False
*/

/*
算法思想：c = a^2 + b^2,将a从0循环遍历到sqrt(c)，b = sqrt(c - a * a),如果c是a^2加上b^2的和，则b * b == c - a * a。
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int srt = sqrt(c);
        for(int i = 0;i <= srt;i++)
        {
            int t = sqrt(c - i * i);
            if(t * t == c -i * i)
                return true;
        }
        return false;
    }
};