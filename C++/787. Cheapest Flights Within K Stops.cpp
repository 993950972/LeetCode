/*
There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
*/

/*
算法思想：使用广度优先，优先队列中存放的一个结构体，该结构体中包含三个元素：当前城市、当前所走步数、当前距离，并且设置优先队列按当前距离进行排序。广度优先遍历。
*/
class Solution {
public:
    struct Node 
    {
        int x,y,z;      //x代表当前城市，y代表当前步数，z代表当前距离
        Node(int a = 0,int b = 0,int c = 0):x(a),y(b),z(c){}
    };
    struct cmp
    {
        bool operator()(Node a,Node b){  //使用优先队列，使其按距离排序
            return a.z > b.z;
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<Node,vector<Node>,cmp> q1;
        map<vector<int>,int> m;
        vector<int> flight;           //作为标记
        Node node;
        node.x = src;
        node.y = 0;
        node.z = 0;
        q1.push(node);
        while(!q1.empty())
        {
            Node curr = q1.top();
            q1.pop();
            if(curr.x == dst && curr.y <= K + 1)
            {
                return curr.z;
            }
            for(int i = 0; i < flights.size();i++)
            {
                if(flights[i][0] == curr.x)
                {
                    flight.clear();
                    flight.push_back(curr.x);
                    flight.push_back(flights[i][1]);
                    if(m.find(flight) == m.end())       //当前航线未访问
                    {
                        Node tmp;
                        tmp.x = flights[i][1];
                        tmp.y = curr.y + 1;
                        tmp.z = curr.z + flights[i][2];
                        q1.push(tmp);
                        m[flight]++;        //做标记
                    }
                }
            }
        }
        return -1;
    }
};

/*
discuss：算法思想：使用动态规划算法。
*/
class Solution {
public:
    //bellman ford.
    //just run it k+1 iterations.
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
        vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: a)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[sink] == 1e8 ? -1 : c[sink];
    }
};
