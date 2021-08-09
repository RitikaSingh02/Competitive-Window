
class Solution {
public:
    //brute force
    vector<Node*>vec;
    bool helper(Node* root, int level , vector<Node*>&vec)
    {
        if (root == NULL) {
            return false;
        }

        if (level == 1)
        {
            vec.push_back(root);
            return true;
        }

        bool left = helper(root->left, level - 1 , vec);
        bool right = helper(root->right, level - 1 , vec);

        return left || right;
    }

    void levelOrderTraversal(Node* root)
    {
        int level = 1;
        while (helper(root, level , vec)) {
            level++;
        }
    }
    void fun( vector<Node*>&v)
    {
        for(int i = 1; i < v.size() ; i++)
        {
            if(i%2!=0)
            {
                //if i is odd that is left child
                //find the parent and point next of this node to the right of the parent

                int parent = (i-1)/2;
                Node* temp = v[i];
                Node* p = v[parent];
                temp->next = p->right;
            }
            else
            {
                //right child of any node
                int parent = (i-2)/2;
                // cout<<parent;
                Node *temp = v[i];
                Node* p = v[parent];
                if(p->next)
                {
                    temp->next = p->next->left;
                }
                else
                {
                    temp->next = NULL;
                }
            }
        }
    }
    Node* connect(Node* root) {
        levelOrderTraversal(root);
        fun( vec);
        return root;
    }
};
