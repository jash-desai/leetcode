class Solution {
public:
    void rec(TreeNode* root, vector<int>&a){
        if(!root) return;
        if(root->left) rec(root->left,a);
        if(root->right) rec(root->right,a);
        a.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> a; rec(root,a);
        return a;
    }
};