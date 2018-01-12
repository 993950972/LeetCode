/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

/*
算法思想：因为之前写过搜索的题目，所以就是用了深度搜索，如果坐标未超过范围且当遇到的是1（陆地）时，将其改为-1，表示已经访问过，并且递归搜索其周围的四个方向，如果超过边界或者遇到的是0（表示河流），则边长加1，否则，表示已经访问过，返回上一级（回溯）。
*/

class Solution {
public:
    //深度搜索
    vector<vector<int>> a;
    int r,c,perimeter = 0;
    void dfs(int x, int y)
    {
        if (x >= 0 && x < r && y >= 0 && y < c && a[x][y] == 1)
        {
            a[x][y] = -1;
            dfs(x - 1,y);
            dfs(x,y - 1);
            dfs(x + 1,y);
            dfs(x,y + 1);
        }
        else if(x >= 0 && x < r && y >= 0 && y < c && a[x][y] == 0 || x < 0 || x >=r || y < 0 || y >= c)
        {
            perimeter++;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        r = grid.size(),c = grid[0].size();
        a = grid;
        for(int i = 0;i < r;i++)
        {
            for(int j = 0;j < c;j++)
            {
                if(grid[i][j])
                {
                    dfs(i,j);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};

/*
discuess：看了discuss才发现自己的代码很low。思想：二层循环遍历地图，统计1的个数且同时统计邻接的矩阵的个数，循环完毕，只需要返回4*（1的个数）- 2*(邻接的矩阵的个数)。
1.find how many 1 in the map. If without the consideration of surrounding cells, the total perimeter should be the total amount of 1 times 4.
2.find how many cell walls that connect with both lands. We need to deduct twice of those lines from total perimeter
*/

int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }
