/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
	Input: "UD"
	Output: true
Example 2:
	Input: "LL"
	Output: false
*/

/*
算法思想：要回到原位置，必须向左移动的次数等于向右移动的次数且向上移动的次数等于向下移动的次数。
*/

class Solution {
public:
    int cnt[4];
    bool judgeCircle(string moves) {
        int len = moves.length();
        for(int i = 0;i < len;i++)
        {
            if(moves[i] == 'L')
                cnt[0]++;
            else if(moves[i] == 'R')
                cnt[1]++;
            else if(moves[i] == 'U')
                cnt[2]++;
            else
                cnt[3]++;
        }
        if(cnt[0] == cnt[1] && cnt[2] == cnt[3])
            return true;
        return false;
    }
};