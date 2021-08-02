class Solution {
public:
    queue<Node*>q;
    void fun(Node*t)
    {
        if(t)
        {
            q.push(t);
            while(q.empty()==false)
            {
                int n = q.size();
                for(int i =0 ; i < n ; i++)
                {
                    Node* temp = q.front();
                    if(n-1 == i)
                    {
                        temp->next = NULL;
                    }
                    q.pop();
                    if(n-1!=i)
                    {
                        temp->next = q.front();
                    }
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
            }
        }
    }
    Node* connect(Node* root) {
        fun(root);
        return root;
    }
};
