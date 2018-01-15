/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

	1.The length of the given array is in range [2, 10,000], and will be even.
	2.The number in given array is in range [-100,000, 100,000].
*/

/*
算法思想：先求出总的果糖的种类数，因为妹妹能拿sz/2个，故取min(总的果糖的种类数,sz/2)即可。
这里使用了unordered_set来统计果糖的种类数。
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int sz = candies.size();
        int ans = 0;
        unordered_set<int> us(candies.begin(),candies.end());
        return min((int)us.size(),sz/2);
    }
};