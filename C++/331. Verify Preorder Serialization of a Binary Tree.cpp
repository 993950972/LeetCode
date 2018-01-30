/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

/*
算法思想：首先将所有的逗号给剔除掉，将所有有效字符串放入vector中。根据二叉树的性质，入度等于出度。且度初始化为1，每遇到一个点肯定有一个出度（包括空节点），如果遇到的是非空节点，则其出度为2.
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.length(),pos = 0,i;
        vector<string> vec;
        for(i = 0;i < len;i++)
        {
            if(preorder[i] == ',')
            {
                vec.push_back(preorder.substr(pos,i - pos));
                pos = i + 1;
            }
        }
        vec.push_back(preorder.substr(pos,i - pos));
        int diff = 1;
       for(int i = 0;i < vec.size();i++)
       {
           if(--diff < 0)
               return false;
           if(vec[i] != "#")
               diff += 2;
       }
        return diff == 0;
    }
};