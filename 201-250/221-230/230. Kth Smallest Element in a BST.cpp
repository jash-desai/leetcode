class Solution {
private:
    void rec(TreeNode* root, int&c, int &k, int&a){
        if(!root) return;
        rec(root->left,c,k,a);
        c++; if(c==k) a = root->val;
        rec(root->right,c,k,a);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int a{-1}, c{0}; rec(root,c,k,a); return a;
    }
};