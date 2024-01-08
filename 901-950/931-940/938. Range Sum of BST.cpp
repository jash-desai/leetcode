class Solution {
    int mn, mx;
private:
    int rec(TreeNode* root){
        if(!root) return 0;
        if(root->val > mx) return rec(root->left);
        if(root->val < mn) return rec(root->right);
        return root->val + rec(root->left) + rec(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int l, int h) {
        if(!root) return 0;
        mn = l; mx = h;
        return rec(root);
    }
};