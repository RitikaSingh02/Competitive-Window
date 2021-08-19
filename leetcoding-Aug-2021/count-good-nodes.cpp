// https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int out = 0;
    int fun(TreeNode* t , int mv , int count)
    {
        if(t)
        {
            if(t->val >= mv)
            {
                mv = t->val;
                count++;
                out++;
            }
            fun(t->left  , mv , count);
            fun(t->right , mv , count);            
            
        }
        return max(out , count);
    }
    int goodNodes(TreeNode* root) {
        fun(root , root->val , 0);
        return out;
    }
};
