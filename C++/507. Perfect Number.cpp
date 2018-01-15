/*
507. Perfect Number
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)

*/

/*
算法思想，直接求该数的小于其本身的所有因数的和即可，然后判断该和与该数是否相等，若相等，返回true，否则返回false。刚开始写，超时，后来改进了，每次求一对因数的和。
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if(num < 6)
            return false;
        for(int i = 2;i * i <= num;i++)		//如果i*i > num，则大于i的因数不需判断，因为前面已经加过了（每次求的是一对因数的和）
        {
            if(num%i == 0)
            {
                sum += i + (num / i);		//每次求一对因数的和。
            }
        }
        sum += 1;
        if(sum == num)
            return true;
        return false;    
    }
};

/*
discuss：可以使用枚举法，考虑到小于1e^8的perfect Number数很少，所以可以使用枚举法。
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        cout<<n.count(num)<<endl;
        return n.count(num);
    }
};