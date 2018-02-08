/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

	It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
	Space complexity should be O(n).
	Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

/*
算法-求二进制数中1的个数
方法：有很多种，详见：https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
第一行代码的作用

先说明一点，以0开头的是8进制数，以0x开头的是十六进制数，上面代码中使用了三个8进制数。

将n的二进制表示写出来，然后每3bit分成一组，求出每一组中1的个数，再表示成二进制的形式。比如n = 50，其二进制表示为110010，分组后是110和010，这两组中1的个数本别是2和3。2对应010，3对应011，所以第一行代码结束后，tmp = 010011，具体是怎么实现的呢？由于每组3bit，所以这3bit对应的十进制数都能表示为2^2 * a + 2^1 * b + c的形式，也就是4a + 2b + c的形式，这里a,b,c的值为0或1，如果为0表示对应的二进制位上是0，如果为1表示对应的二进制位上是1，所以a + b + c的值也就是4a + 2b + c的二进制数中1的个数了。举个例子，十进制数6（0110）= 4 * 1 + 2 * 1 + 0，这里a = 1, b = 1, c = 0, a + b + c = 2，所以6的二进制表示中有两个1。现在的问题是，如何得到a + b + c呢？注意位运算中，右移一位相当于除2，就利用这个性质！

4a + 2b + c 右移一位等于2a + b

4a + 2b + c 右移量位等于a

然后做减法

4a + 2b + c –(2a + b) – a = a + b + c，这就是第一行代码所作的事，明白了吧。

第二行代码的作用

在第一行的基础上，将tmp中相邻的两组中1的个数累加，由于累加到过程中有些组被重复加了一次，所以要舍弃这些多加的部分，这就是&030707070707的作用，又由于最终结果可能大于63，所以要取模。

需要注意的是，经过第一行代码后，从右侧起，每相邻的3bit只有四种可能，即000, 001, 010, 011，为啥呢？因为每3bit中1的个数最多为3。所以下面的加法中不存在进位的问题，因为3 + 3 = 6，不足8，不会产生进位。

tmp + (tmp >> 3)-这句就是是相邻组相加，注意会产生重复相加的部分，比如tmp = 659 = 001 010 010 011时，tmp >> 3 = 000 001 010 010，相加得

001 010 010 011

000 001 010 010

---------------------

001 011 100 101

011 + 101 = 3 + 5 = 8。（感谢网友Di哈指正。）注意，659只是个中间变量，这个结果不代表659这个数的二进制形式中有8个1。

注意我们想要的只是第二组和最后一组（绿色部分），而第一组和第三组（红色部分）属于重复相加的部分，要消除掉，这就是&030707070707所完成的任务（每隔三位删除三位），最后为什么还要%63呢？因为上面相当于每次计算相连的6bit中1的个数，最多是111111 = 77（八进制）= 63（十进制），所以最后要对63取模。
*/
class Solution {
public:
   int BitCount5(int n) 
    {
        unsigned int tmp = n - ((n >>1) &033333333333) - ((n >>2) &011111111111);
        return ((tmp + (tmp >>3)) &030707070707) %63;
    }
    vector<int> countBits(int num) {
         vector<int> ans;
         int n = 0;
         for(int i = 0;i <= num;i++)
         {
             n = BitCount5(i);
             ans.push_back(n);
         }
        return ans;
    }
};

/*
discuss: i&(i - 1)相当于把从右往左的第一个1给删除，故ret[i] = ret[i&(i - 1)] + 1。
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
