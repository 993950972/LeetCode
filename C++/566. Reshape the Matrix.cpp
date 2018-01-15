/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
	1.The height and width of the given matrix is in range [1, 100].
	2.The given r and c are all positive.
*/

/*
算法思想：判断能否转换，如果不能，则返回原矩阵，否则循环遍历原矩阵，当字符数字等于c，换行；否则，重置cnt。
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<int> row;
        vector<vector<int>> matrix;
        int r0 = nums.size(),c0 = nums[0].size();
        if(r0 * c0 != r * c)
            return nums;
        int cnt = 0;
        for(int i = 0;i < r0;i++)
        {
            for(int j = 0;j < c0;j++)
            {
                if(cnt != c || row.empty())
                {
                    row.push_back(nums[i][j]);
                    cnt++;
                }
                else
                {
                    matrix.push_back(row);
                    row.clear();
                    row.push_back(nums[i][j]);
                    cnt = 1;
                }
                
            }
        }
        if(!row.empty())
        {
            matrix.push_back(row);
        }
        return matrix;
    }
};

/*
discuss
*/
public int[][] matrixReshape(int[][] nums, int r, int c) {
    int n = nums.length, m = nums[0].length;
    if (r*c != n*m) return nums;
    int[][] res = new int[r][c];
    for (int i=0;i<r*c;i++) 
        res[i/c][i%c] = nums[i/m][i%m];
    return res;
}