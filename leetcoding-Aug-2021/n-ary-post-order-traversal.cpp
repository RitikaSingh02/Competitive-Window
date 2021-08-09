// https://leetcode.com/problems/n-ary-tree-postorder-traversal
class Solution {
public:
    vector<int>res;
    void fun(Node *t)
    {
        if(!t)
            return;
        for(auto i : t->children)
        {
            fun(i);
            res.push_back(i->val);
        }
    }
    vector<int> postorder(Node* root) {
        fun(root);
        if(root)
            res.push_back(root->val);
        return res;
            
    }
};
