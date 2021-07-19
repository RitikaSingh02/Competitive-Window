//https://leetcode.com/problems/deepest-leaves-sum/
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
    int ht;
    int max_height(TreeNode *t)
    {
        if(t)
        {
            int l = max_height(t->left);
            int r = max_height(t->right);
            return max(l , r) +1;
        }
        return 0;
    }
    int sum =0 ;
    int fun(TreeNode * t , int h)
    {
        if(t)
        {
            if(t->left == NULL && t->right == NULL)
            {
                //a leaf node
                if(h == ht)
                {
                    sum+=t->val;
                    // cout<<"y";
                    return sum;
                }
            }
            fun(t->left , h+1);
            fun(t->right , h+1);
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        //cal max height
        ht = max_height(root);
        cout<<ht;
        return fun(root , 1);
    }
};
