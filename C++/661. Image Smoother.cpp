/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
	Input:
	[[1,1,1],
	 [1,0,1],
	 [1,1,1]]
	Output:
	[[0, 0, 0],
	 [0, 0, 0],
	 [0, 0, 0]]
	Explanation:
	For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
	For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
	For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
	1.The value in the given matrix is in the range of [0, 255].
	2.The length and width of the given matrix are in the range of [1, 150].
*/

/*
算法思想：使用二维数组存其八个方向，然后循环遍历矩阵，对每个元素求与其周围元素和，然后除以其个数，得到的商放入结果矩阵中。
*/
class Solution {
public:
    int dir[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int sz0 = M.size(),sz1 = M[0].size();
        int temp,x,y,cnt;
        vector<vector<int>> ans(sz0,vector<int>(sz1,0));
        for(int i = 0;i < sz0;i++)
        {
            for(int j = 0;j < sz1;j++)
            {
                temp = M[i][j];
                cnt = 1;
                for(int k = 0;k < 8;k++)
                {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if(x >= 0 && x < sz0 && y >= 0 && y < sz1)
                    {
                        temp += M[x][y];
                        cnt++;
                    }
                }
                ans[i][j] = temp/cnt;
            }
        }
        return ans;
    }
};

/*
discuss：Derived from StefanPochmann’s idea in “game of life”: the board has ints in [0, 255], hence only 8-bit is used, we can use the middle 8-bit to store the new state (average value), replace the old state with the new state by shifting all values 8 bits to the right.
主要不同之处在于存储数据时，其使用了原矩阵，因为数据范围在0~255，故只需要将结果左移8位，其结果就不会改变其最低8位的数据，也即不会改变其原来的值。
Derived from StefanPochmann’s idea in “game of life”: the board has ints in [0, 255], hence only 8-bit is used, we can use the middle 8-bit to store the new state (average value), replace the old state with the new state by shifting all values 8 bits to the right.
*/

 vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        if (m == 0 || n == 0) return {{}};
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = M[i][j], cnt = 1;
                for (int k = 0; k < dirs.size(); k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x > m - 1 || y < 0 || y > n - 1) continue;
                    sum += (M[x][y] & 0xFF);
                    cnt++;
                }
                M[i][j] |= ((sum / cnt) << 8);
            }
        }
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] >>= 8;
            }
         }
        return M;
    }

