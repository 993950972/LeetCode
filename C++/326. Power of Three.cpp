/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

/*
算法思想：素数的幂指数有一个特点，假如N是n的幂指数，其所有小于N且是N的约数的正整数都是n的幂指数。故这道题可以先求出int范围内的3的最大幂指数max，然后在判断num是否是max的约数。
*/

class Solution {
public:
    #define MinValue 
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
       return !fmod(log(n)/log(3),1) == 0;
    }
};

/*
discuess:求判断一个数是否为另一个数的幂指数是一类题目。
方法：1.枚举算法，毕竟int 或者long范围有限，而指数是爆炸型的，其增长速度特别大，所有在有限的范围内也是很容易列举一个数（大于1）的所有幂指数。用到的数据类型：数组、hash集
2. 如果判断的是一个素数的幂指数的话，方法（1）：可以如上所示，先求出其最大幂指数，然后再用最大的幂指数对需要判断的数进行求模即可。
方法（2）：可以使用换底公式log(num)/log(n)，最后判断得到的值是否为一个整数（可以对1进行求模）。
3.如果判断的是2或者4的幂指数的话，可以使用按为位操作来进行。
1、判断n是否为2的幂？

①、任何整数乘以2，都相当于向左移动了一位，而2的0次幂为1，所以2的n次幂就是1向左移动n位。这样，2的幂的特征就是二进制表示只有最高位为1，其他位均为0。那么，我们只要判断一个数的二进制表示只有一个1，那么它就是2的幂。

②、n为整数，则n & (n - 1)可以消除n二进制表示的最低位的1，这个方法可以用来统计一个数二进制中1的个数，当然也可以用来判断是否为2的幂。如下：

2、判断n是不是4的幂？

①、4的幂首先是2的幂，因为4^n = （2^2）^n，故可以先判断是否为2的幂，同样利用n & (n - 1);

②、唯一的不同是，4的幂的二进制表示中，1全奇数位上。所以进一步判断其与0x55555555按位与的结果，0x55555555是十六进制表示，换成二进制表示，可以发现，其奇数位上全是1，那么相与结果为true，则是4的幂，否则不是。

具体总结如下：
Two trivial solutions first:
#Recursive Solution#

public boolean isPowerOfThree(int n) {
    return n>0 && (n==1 || (n%3==0 && isPowerOfThree(n/3)));
}
#Iterative Solution#

update following Stefan’s answer below:

public boolean isPowerOfThree(int n) {
    if(n>1)
        while(n%3==0) n /= 3;
    return n==1;
}
my original code:
public boolean isPowerOfThree(int n) {
while(n>1) {
if(n%3!=0) return false;
n /= 3;
}
return n<=0 ? false : true;
}

#It’s all about MATH…#

Method 1

Find the maximum integer that is a power of 3 and check if it is a multiple of the given input. (related post)

public boolean isPowerOfThree(int n) {
    int maxPowerOfThree = (int)Math.pow(3, (int)(Math.log(0x7fffffff) / Math.log(3)));
    return n>0 && maxPowerOfThree%n==0;
}
Or simply hard code it since we know maxPowerOfThree = 1162261467:

public boolean isPowerOfThree(int n) {
    return n > 0 && (1162261467 % n == 0);
}
It is worthwhile to mention that Method 1 works only when the base is prime. For example, we cannot use this algorithm to check if a number is a power of 4 or 6 or any other composite number.

Method 2

If log10(n) / log10(3) returns an int (more precisely, a double but has 0 after decimal point), then n is a power of 3. (original post). But be careful here, you cannot use log (natural log) here, because it will generate round off error for n=243. This is more like a coincidence. I mean when n=243, we have the following results:

log(243) = 5.493061443340548    log(3) = 1.0986122886681098
   ==> log(243)/log(3) = 4.999999999999999

log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
   ==> log10(243)/log10(3) = 5.0
This happens because log(3) is actually slightly larger than its true value due to round off, which makes the ratio smaller.

public boolean isPowerOfThree(int n) {
    return (Math.log10(n) / Math.log10(3)) % 1 == 0;
}
Method 3 related post

public boolean isPowerOfThree(int n) {
    return n==0 ? false : n==Math.pow(3, Math.round(Math.log(n) / Math.log(3)));
}
Method 4 related post

public boolean isPowerOfThree(int n) {
    return n>0 && Math.abs(Math.log10(n)/Math.log10(3)-Math.ceil(Math.log10(n)/Math.log10(3))) < Double.MIN_VALUE;
}
Cheating Method

This is not really a good idea in general. But for such kind of power questions, if we need to check many times, it might be a good idea to store the desired powers into an array first. (related post)

public boolean isPowerOfThree(int n) {
    int[] allPowerOfThree = new int[]{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
    return Arrays.binarySearch(allPowerOfThree, n) >= 0;
}
or even better with HashSet:

public boolean isPowerOfThree(int n) {
    HashSet<Integer> set = new HashSet<>(Arrays.asList(1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467));
    return set.contains(n);
}
#New Method Included at 15:30pm Jan-8th#

Radix-3 original post

The idea is to convert the original number into radix-3 format and check if it is of format 10* where 0* means k zeros with k>=0.

public boolean isPowerOfThree(int n) {
    return Integer.toString(n, 3).matches("10*");
}
*/