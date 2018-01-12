/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

/*
算法思想：使用异或就可以，比如5（101）与7（111）异或就可以。
*/

class Solution {
public:
    int findComplement(int num) {
        int nums = 0,temp = num;
        while(temp)
        {
            nums++;
            temp/=2;
        }
        return (num^((int)(pow(2,nums) - 1)));
    }
};