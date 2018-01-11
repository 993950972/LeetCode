/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

/*
算法思想：可以使用排列组合，先取三个数的组合，然后对这三个数进行排列。最后计算距离，并判断是否相等。这样做提交之后，只能通过24个样例，还有7个样例不能通过，会超时。
discuss：这里使用unordered_map来记录，其key有记录distance，value记录从所有点到点i的距离为distance的节点数。
*/

class Solution {
public:
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int booms = 0;
        for(auto& p : points)
        {
            unordered_map<int,int> um(points.size());
            for(auto& q: points)
            {
                int x = p.first - q.first;
                int y = p.second - q.second;
                int dis = x*x+y*y;
                booms += 2*um[dis]++;
            }
        }
        return booms;
    }
};

/*
算法思想：用排列组合，结果超时。
*/
class Solution {
public:
    vector<vector<int>> vec1;
    vector<int> vec;
    void assemble(int n, int r)
    {
        int* a = new int[r];
        for(int i = 0;i < r;i++)
        {
            a[i] = i;
            vec.push_back(a[i]);
        }
        vec1.push_back(vec);
       // cout<<"//////////////"<<endl;
        for(int i = r - 1;i >= 0;i--)
        {
            if(a[i] < n - r + i)
            {
                a[i]++;
                for(int j = i + 1;j < r;j++)
                {
                    a[j] = a[j - 1] + 1;
                }
                vec.clear();
                for(int k = 0;k < r;k++)
                {
                    vec.push_back(a[k]);
                }
                vec1.push_back(vec);
                i = r;
            }
        }
        cout<<"//////////////"<<endl;
    }
    
    int isEqual(vector<pair<int, int>>& points,vector<int> pos)
    {
        int ans = 0;
        double dis1,dis2,disX1,disY1,disX2,disY2;
        disX1 = points[pos[0]].first - points[pos[1]].first;
        disY1 = points[pos[0]].second - points[pos[1]].second;
        disX2 = points[pos[0]].first - points[pos[2]].first;
        disY2 = points[pos[0]].second - points[pos[2]].second;
        dis1 = disX1 * disX1 + disY1 * disY1;
        dis2 = disX2 * disX2 + disY2 * disY2;
        dis1 = disX1 * disX1 + disY1 * disY1;
        dis2 = disX2 * disX2 + disY2 * disY2;
        
        if(dis1 == dis2)
            ans += 2;
        //////////////////////////
        disX1 = points[pos[1]].first - points[pos[0]].first;
        disY1 = points[pos[1]].second - points[pos[0]].second;
        disX2 = points[pos[1]].first - points[pos[2]].first;
        disY2 = points[pos[1]].second - points[pos[2]].second;
        dis1 = disX1 * disX1 + disY1 * disY1;
        dis2 = disX2 * disX2 + disY2 * disY2;
        
         if(dis1 == dis2)
            ans += 2;
        /////////////////////////////
        disX1 = points[pos[2]].first - points[pos[0]].first;
        disY1 = points[pos[2]].second - points[pos[0]].second;
        disX2 = points[pos[2]].first - points[pos[1]].first;
        disY2 = points[pos[2]].second - points[pos[1]].second;
        dis1 = disX1 * disX1 + disY1 * disY1;
        dis2 = disX2 * disX2 + disY2 * disY2;
        
         if(dis1 == dis2)
            ans += 2;
        return ans;
    }
                 
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        assemble(points.size(),3);
        for(int i = 0;i < vec1.size();i++)
        {
            cout<<vec1[i][0]<<" "<<vec1[i][1]<<" "<<vec1[i][2]<<endl;
            ans += isEqual(points,vec1[i]);
        }
        return ans;
    }
};