// https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    unordered_map<int , int> hash;
    vector<int> max_count(unordered_map<int , int>hash)
    {
        int ans = INT_MIN;
        vector<int>res;
        for(auto i : hash)
        {
            if(i.second>ans)
                ans = i.second;
        }
        for(auto i : hash)
        {
            if(i.second == ans)
                res.push_back(i.first);
        }
        return res;
    }
    void fun(TreeNode* t)
    {
        if(t)
        {
            if(hash.find(t->val)== hash.end())
            {
                //insert into the map
                hash[t->val] = 1;
            }
            else
            {
                //already present
                hash[t->val]+=1;
            }
            fun(t->left);
            fun(t->right);
        }
        return;
    }
    vector<int> findMode(TreeNode* root) {
        fun(root);
        return max_count(hash);
    }
};
