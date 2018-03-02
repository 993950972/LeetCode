/*
Given a graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent ubsets.
*/

/*
题目意思：判断一个图是否能分成两个子集，满足图中所有边的两端点均不在同一集合中。
算法思想：图的问题可以使用着色来解决，问题转化成相邻节点不能着同一颜色。可以使用深度搜索和广度搜索来解决。
*/

//深度搜索：但是会超时
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> colors,int color,int node)	//深度搜索
    {
        if(colors[node] != -1)					//如果已经着色，判断当前涂色是否与已着色相同
        {
            return colors[node] == color;
        }
        colors[node] = color;					//如果未着色，则将其着色
        int sz = graph[node].size();
        for(int i = 0;i < sz;i++)				//递归调用，将当前节点的邻接点进行着色
        {
            if(!dfs(graph,colors,1 - color,graph[node][i]))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);
        for(int i = 0;i < graph.size();i++)	//图可能是非连通图，故需要判断每个子图是否均是二分图
        {
            if(colors[i] == -1 && !dfs(graph,colors,0,i))
                return false;
        }
        return true;
    }
};

//广度搜索，首先将当前搜索的点着色，然后放入队列中，继续搜索其相邻的节点，如果不能按照约束进行着色，则返回false，如果所有的节点均能按照约束进行着色，则返回true。
//广度搜索不会超时
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() < 3)
            return true;
        vector<int> colors(graph.size(),-1);
        queue<int> q;
        for(int i = 0;i < graph.size();i++)
        {
            if(colors[i] == -1)
            {
                colors[i] = 0;
                q.push(i);
            }
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int j = 0;j < graph[node].size();j++)
                {
                    if(colors[graph[node][j]] == -1)
                    {
                        colors[graph[node][j]] = colors[node] == 0?1:0;
                        q.push(graph[node][j]);
                    }
                    else if(colors[node] == colors[graph[node][j]])
                        return false;
                }
            }
        }
        return true;
    }
};