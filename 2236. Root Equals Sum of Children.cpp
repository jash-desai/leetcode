class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return false;
        return (root->left->val + root->right->val == root->val);
    }
};