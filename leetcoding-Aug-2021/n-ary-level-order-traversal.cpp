class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        if(root)
        {
            q.push(root);
            }
        else
            return res;
        while(!q.empty())
        {
            vector<int>temp;
            int n = q.size();
            for(int i = 0 ; i <n ; i++)            
            {
                Node *t = q.front();
                q.pop();
                temp.push_back(t->val);
                for(auto j : t->children)
                {
                    q.push(j);
                }

            }
                res.push_back(temp);
                temp.clear();
            
        }
        return res;
    }
};
