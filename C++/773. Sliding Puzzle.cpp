/*
773. Sliding Puzzle My SubmissionsBack to Contest
User Accepted: 378
User Tried: 458
Total Accepted: 381
Total Submissions: 759
Difficulty: Hard
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
*/

/*
算法思想：广度优先遍历。很明显的搜索题目。从一个状态到另一个状态，一般使用广度优先遍历。广度优先使用队列，不需要进行递归，求解最多需要多少步到达最终状态可使用两个队列来进行，没交换一次，表示操作一步。这个题目的技巧是在记录已经遍历过的状态时可以使用map来进行记录。
*/
class Solution {
public:
    map<vector<vector<int> >, int> mp;
    vector<vector<int>> boardbak;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int cnt = 0;
    int slidingPuzzle(vector<vector<int>>& board) {
        boardbak = board;
        int ans = bfs();
        return ans;
    }
private:
    int bfs()
    {
        queue<vector<vector<int>>> q,q1;
        vector<vector<int>> s;
        q.push(boardbak);
        int x,y;
        cout<<"////////////"<<endl;
        while(!q1.empty() || !q.empty())
        {
            while(!q.empty())
            {
                s = q.front();
                q.pop();
                if(s[0][0] == 1 && s[0][1] == 2 && s[0][2] == 3 && s[1][0] == 4 && s[1][1] == 5 && s[1][2] == 0)
                {
                    cout<<"yes"<<endl;
                    return cnt;
                }
                for(int i = 0;i < 2;i++)
                {
                    for(int j = 0;j < 3;j++)
                    {
                        if(s[i][j] == 0)
                        {
                            x = i;
                            y = j;
                        }
                    }
                }
                mp[s]++;
                for(int i = 0;i < 4;i++)
                {
                    int new_x = x + dir[i][0],new_y = y + dir[i][1];
                    vector<vector<int>> temp = s;
                    if(new_x >= 0 && new_x <= 1 && new_y >= 0 && new_y <= 2)
                    {
                        swap(temp[new_x][new_y],temp[x][y]);
                        if(mp.find(temp) == mp.end())
                        {
                            mp[temp]++;
                            q1.push(temp);
                        }
                        else
                            continue;
                    }
                }
            }
            if(!q1.empty())
            {
                swap(q,q1);
                cnt++;
            }
        }
        return -1;
    }
};