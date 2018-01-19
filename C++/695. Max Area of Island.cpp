/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
	[[0,0,1,0,0,0,0,1,0,0,0,0,0],
	 [0,0,0,0,0,0,0,1,1,1,0,0,0],
	 [0,1,1,0,1,0,0,0,0,0,0,0,0],
	 [0,1,0,0,1,1,0,0,1,0,1,0,0],
	 [0,1,0,0,1,1,0,0,1,1,1,0,0],
	 [0,0,0,0,0,0,0,0,0,0,1,0,0],
	 [0,0,0,0,0,0,0,1,1,1,0,0,0],
	 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
	Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
	[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

/*
算法思想：深度搜索，并标记遍历过的岛屿点。
*/
class Solution {
public:
    int ans = 0,sz1,sz2;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxnum = 0;
        sz1 = grid.size();
        sz2 = grid[0].size();
        for(int i = 0;i < sz1;i++)
        {
            for(int j = 0;j < sz2;j++)
            {
                if(grid[i][j])
                {
                    ans = 0;
                    dfs(i,j,grid);
                    maxnum = max(maxnum,ans);
                }
            }
        }
        return maxnum;
    }
private:
    void dfs(int x,int y,vector<vector<int>>& map)
    {
        if(x >= 0 && x < sz1 && y >= 0 && y < sz2 && map[x][y])
        {
            ans++;
            map[x][y] = 0;
            dfs(x + 1,y,map);
            dfs(x - 1,y,map);
            dfs(x,y + 1,map);
            dfs(x,y - 1,map);
        }
    }
};