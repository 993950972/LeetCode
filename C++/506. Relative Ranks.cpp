/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
	1.N is a positive integer and won't exceed 10,000.
	2.All the scores of athletes are guaranteed to be unique.
*/

/*
算法思想：声明一个nums的备份数据numbak，对numbak进行排序，然后循环遍历nums，对当前数在排好序的numbak数组中进行查找，当找到之后，判断是否在前三，如果在，则结果集中填入相应字符串，否则填入对应的位置（转换成字符串）。
*/

class Solution {
public:
    string numToStr(int num)
    {
        string str;
        while(num)
        {
            str += (num%10) + '0';
            num /= 10;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans;
        string str;
        vector<int> numbak = nums;
        sort(numbak.begin(),numbak.end(),greater<int>());
        int len = nums.size();
        for(int i = 0;i < len;i++)
        {
            for(int j = 0;j < len;j++)
            {
                if(nums[i] == numbak[j])
                {
                    if(j == 0)
                    {
                        str = "Gold Medal";
                    }
                    else if(j == 1)
                    {
                        str = "Silver Medal";
                    }
                    else if(j == 2)
                    {
                        str = "Bronze Medal";
                    }
                    else
                    {
                        str = numToStr(j + 1);
                    }
                    ans.push_back(str);
                    break;
                }
            }
        }
        return ans;
    }
};

/*
discuess：使用优先队列来存储nums中的数据和其位置，放入优先队列后会自动对nums中数据进行排序，后只需要遍历优先队列即可。
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int sz = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i < sz;i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> ans(sz,"");
        pair<int,int> p;
        for(int i = 0;i < sz;i++)
        {
            p = pq.top();
            pq.pop();
            if(i == 0)
            {
                ans[p.second] = "Gold Medal";
            }
            else if(i == 1)
            {
                ans[p.second] = "Silver Medal";
            }
            else if(i == 2)
            {
                ans[p.second] = "Bronze Medal";
            }
            else
            {
                ans[p.second] = to_string(i + 1);
            }
        }
        return ans;
    }
};