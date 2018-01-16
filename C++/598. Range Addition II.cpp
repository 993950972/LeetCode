/*
Given an m * n matrix M initialized with all 0's and several update operations.

Operations are represented by a 2D array, and each operation is represented by an array with two positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.

You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.

Note:
	1.The range of m and n is [1,40000].
	2.The range of a is [1,m], and the range of b is [1,n].
	3.The range of operations size won't exceed 10,000.
*/
/*
算法思想：如果没有操作，则矩阵中所有值均为0（都同样大小，则返回其矩阵大小即可），否则返回其ope[i][0]的最小值与ops[i][1]的最小值的乘积即可。因为每一次操作这个范围的数均被加一次，故最大，且相等。
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a,b;
        if(ops.size() < 1)
            return m * n;
        a = ops[0][0],b = ops[0][1];
        for(int i = 1;i < ops.size();i++)
        {
            a = min(ops[i][0],a);
            b = min(ops[i][1],b);
        }
        cout<<a<<" "<<b<<endl;
        return a * b;
    }
};
