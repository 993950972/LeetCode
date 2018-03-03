/*
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
Note:

	1.answers will have length at most 1000.
	2.Each answers[i] will be an integer in the range [0, 999].
*/

/*
算法思想：要求满足条件的最小兔子的数量，考虑有x+1个兔子的颜色是相同的，我们可以得到最多可以有x+1个兔子可以回答有x个兔子其颜色与之相同。如果有n个兔子回答x个兔子颜色与之相同：1）n%(x + 1) == 0,则我们可以得到有n/(x + 1)组兔子（每组x+1个兔子）
2）如果n%(x + 1) != 0，1）n%(x + 1) == 0,则我们可以得到有n/(x + 1) + 1组兔子（每组x+1个兔子）。
然后将每种颜色不同的兔子加起来即可。

If x+1 rabbits have same color, then we get x+1 rabbits who all answer x.
now n rabbits answer x.
If n%(x+1)==0, we need n/(x+1) groups of x+1 rabbits.
If n%(x+1)!=0, we need n/(x+1) + 1 groups of x+1 rabbits.

the number of groups is math.ceil(n/(x+1)) and it equals to (n+i)/(i+1) , which is more elegant.
*/
int numRabbits(vector<int>& answers) {
        map<int, int> c;
        for (int i : answers) c[i]++; 	//map<int,int>其first代表x，second代表n
        int res = 0;
        for (auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
	
/*
算法思想：排序，然后处理回答相同的兔子数量，既然要求最少兔子数量，则回答相同的兔子尽可能是属于同一颜色，除非超过x + 1个兔子回答x，则需要另取新组。
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0,i = 0,j = 0,k,flag = 0;
        sort(answers.begin(),answers.end());
        for(i = 0;i < answers.size() && j < answers.size();i++)
        {
            ans += 1 + answers[i];
            cout<<ans<<endl;
            for(k = 0,j = i + 1;k <= answers[i] && answers[j] == answers[i];i++,k++)
            {
                flag = 1;
            }
            if(flag)
            {
                flag = 0;
                i--;
            }
        }
        return ans;
    }
};
