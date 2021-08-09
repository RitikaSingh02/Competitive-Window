// https://leetcode.com/problems/path-sum-ii
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
    vector<vector<int>>res;
    void fun(TreeNode *t , int target , int sum, vector<int>temp)
    {
        if(t)        
        {
            sum+=t->val;
            if(!t->left && !t->right)
            {
                if(sum==target)
                {
                    temp.push_back(t->val);
                    //leaf node
                    res.push_back(temp);
                    temp.pop_back();
                }
                return;
                
            }
            temp.push_back(t->val);
            fun(t->left,target,sum,temp);
            fun(t->right,target,sum,temp);
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            fun(root, targetSum , 0 , {});
            return res;
        }
        else
            return {};
    }
};
