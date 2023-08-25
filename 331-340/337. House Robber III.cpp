class Solution {
private:
    pair<int, int> rec(TreeNode* root){
        if(!root) return {0, 0};
        auto [ans1l, ans2l] = rec(root->left);
        auto [ans1r, ans2r] = rec(root->right);
        return {root->val + ans2l + ans2r, max(ans1l, ans2l) + max(ans1r, ans2r)};
    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return root->val;
        auto [ans1, ans2] = rec(root);
        return max(ans1, ans2);
    }
};