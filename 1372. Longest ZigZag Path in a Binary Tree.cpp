class Solution {
    int ans = 0;
public:
    int dfs(TreeNode* root, bool left) {
        if (!root) return -1;
        int l =1+dfs(root->left, false);
        int r =1+dfs(root->right, true);
        ans = max(ans, max(l, r));
        
        return left ? l : r ;
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, true); 
        return ans;
    }
};