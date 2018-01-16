/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
	Input: flowerbed = [1,0,0,0,1], n = 1
	Output: True
Example 2:
	Input: flowerbed = [1,0,0,0,1], n = 2
	Output: False
Note:
	1.The input array won't violate no-adjacent-flowers rule.
	2.The input array size is in the range of [1, 20000].
	3.n is a non-negative integer which won't exceed the input array size.
*/

/*
算法思想：贪心法。遍历一遍flowerbed数组，如果当前元素为0，则判断当前元素能否种花，如果可以，则更新flowerbed数组，且cnt加1，最后判断cnt是否大于等于n，如果大于，说明可以种下n朵花，否则不能。
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int cnt = 0;
        if(n <= 0)
            return true;
        if(sz == 1 && n == 1 && !flowerbed[0])
            return true;
        if(sz < 2)
            return false;
        for(int i = 0;i < sz;i++)
        {
            if(!flowerbed[i] && (i == 0 && !flowerbed[i + 1] || i == sz - 1 && !flowerbed[i - 1] || !flowerbed[i - 1] && !flowerbed[i + 1]))
            {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        if(cnt >= n)
            return true;
        return false;
    }
};
