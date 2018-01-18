/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

	1.Integer (one round's score): Directly represents the number of points you get in this round.
	2."+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
	3."D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
	4."C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
	Input: ["5","2","C","D","+"]
	Output: 30
	Explanation: 
	Round 1: You could get 5 points. The sum is: 5.
	Round 2: You could get 2 points. The sum is: 7.
	Operation 1: The round 2's data was invalid. The sum is: 5.  
	Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
	Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
	Input: ["5","-2","4","C","D","9","+","+"]
	Output: 27
	Explanation: 
	Round 1: You could get 5 points. The sum is: 5.
	Round 2: You could get -2 points. The sum is: 3.
	Round 3: You could get 4 points. The sum is: 7.
	Operation 1: The round 3's data is invalid. The sum is: 3.  
	Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
	Round 5: You could get 9 points. The sum is: 8.
	Round 6: You could get -4 + 9 = 5 points. The sum is 13.
	Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
	The size of the input list will be between 1 and 1000.
	Every integer represented in the list will be between -30000 and 30000.

*/

/*
算法思想：使用vector来记录每次获得的分数，sum来记录截止到当前回合获得的总分数，vector可以模拟栈。是用curr记录本场得分，vector记录历史得分。
*/

class Solution {
public:
    int strToNum(string str)
    {
        int len = str.length();
        int ans = 0,flag = 0;
        for(int i = 0;i < len;i++)
        {
            if(str[i] != '-')
            {
                ans *= 10;
                ans += str[i] - '0';
            }
            else
                flag = 1;
        }
        if(flag)
            return -ans;
        return ans;
    }
    int calPoints(vector<string>& ops) {
        int sz = ops.size();
        vector<int>  vec;                   //存每个回合获得的分数
        int sum = 0,curr,pre;
        for(int i = 0;i < sz;i++)
        {
            if(ops[i] != "+" && ops[i] != "D" && ops[i] != "C")     //如果是数字，直接放入vector中，且sum更新
            {
                curr = strToNum(ops[i]);
                vec.push_back(curr);
                sum += curr;
            }
            else if(ops[i] == "+")                                  //如果是加号，则此次获得的分数是上两场的和，放入vector中，且sum更新
            {
                curr = vec[vec.size() - 1] + vec[vec.size() - 2];
                vec.push_back(curr);
                sum += curr;
            }
            else if(ops[i] == "D")                                  //如果是"D"，则说明本场获得分数是上一场的两倍，放入vector中，且更新vector
            {
                curr = vec[vec.size() - 1] * 2;
                vec.push_back(curr);
                sum += curr;
            }
            else                                                    //否则就是"C"，说明上一场无效，相当于本场获得的分数是上一场的相反数，将本场分数放入vector中，且更新sum
            {
                curr = 0 - vec[vec.size() - 1];
                vec.pop_back();
                sum += curr;
            }
        }
        return sum;
    }
};


/*
discuss：算法类似，不过存放历史数据使用的是单链表。
Java version：
*/
class Solution {
    public int calPoints(String[] ops) {
        int sum = 0;
        LinkedList<Integer> list = new LinkedList<>();
        for (String op : ops) {
            if (op.equals("C")) {
                sum -= list.removeLast();
            }
            else if (op.equals("D")) {
                list.add(list.peekLast() * 2);
                sum += list.peekLast();
            }
            else if (op.equals("+")) {
                list.add(list.peekLast() + list.get(list.size() - 2));
                sum += list.peekLast();
            }
            else {
                list.add(Integer.parseInt(op));
                sum += list.peekLast();
            }
        }
        return sum;
    }
}