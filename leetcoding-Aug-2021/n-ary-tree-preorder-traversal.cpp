//https://leetcode.com/problems/n-ary-tree-preorder-traversal
class Solution {
public:
    vector<int>res;
    void fun(Node*t)
    {
        if(!t)
            return;
        res.push_back(t->val);
        
        for(auto i : t->children)
        {
            fun(i);
        }
        
    }
    vector<int> preorder(Node* root) {
        fun(root);        
        return res;
    }
};
