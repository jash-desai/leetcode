class Solution {
public:
    int rec(TreeNode* root){
        if(!root) return 0;
        int lh = rec(root->left), rh = rec(root->right);
        if(lh==-1 or rh==-1 or abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
       if(!root) return 1;
       return (rec(root) != -1);  
    }
};