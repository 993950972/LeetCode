/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
	Input: Binary tree: [1,2,3,4]
		   1
		 /   \
		2     3
	   /    
	  4     

	Output: "1(2(4))(3)"

	Explanation: Originallay it needs to be "1(2(4)())(3()())", 
	but you need to omit all the unnecessary empty parenthesis pairs. 
	And it will be "1(2(4))(3)".
Example 2:
	Input: Binary tree: [1,2,3,null,4]
		   1
		 /   \
		2     3
		 \  
		  4 

	Output: "1(2()(4))(3)"

	Explanation: Almost the same as the first example, 
	except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string ans;
    string numToStr(int num)
    {
        string str;
        int flag = 0;
        if(num == 0)
            return "0";
        if(num < 0)
        {
            flag = 1;
            num = -num;
        }
        while(num > 0)
        {
            str += num % 10 + '0';
            num /= 10;
        }
        if(flag) str += "-";
        reverse(str.begin(),str.end());
        return str;
    }
    string tree2str(TreeNode* t) {
        if(t)
        {
            if(t->left && t->right) 
            {
                ans = numToStr(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
            }
            else if(t->left)
            {
                ans = numToStr(t->val) + "(" + tree2str(t->left) + ")";
            }
            else if(t->right)
            {
                ans = numToStr(t->val) + "()" + "(" + tree2str(t->right) + ")";
            }
            else
                ans = numToStr(t->val);
        }
        return ans;
    }
};

/*
discuss：递归，别人的代码很简洁。值得借鉴。
*/

public class Solution {
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        
        String result = t.val + "";
        
        String left = tree2str(t.left);
        String right = tree2str(t.right);
        
        if (left == "" && right == "") return result;
        if (left == "") return result + "()" + "(" + right + ")";
        if (right == "") return result + "(" + left + ")";
        return result + "(" + left + ")" + "(" + right + ")";
    }
}