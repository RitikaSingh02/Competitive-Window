class Solution {
public:
    bool mirror(TreeNode * l,TreeNode * r)
    {
        if(l==NULL and r==NULL)
            return true;
        if (l==NULL || r==NULL)
            return false;
            return(l->val==r->val) && mirror(l->right,r->left) && mirror(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root,root);
        
    }
    
};