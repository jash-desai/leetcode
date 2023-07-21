class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        int ans = 1; q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            int s = q.front().second;
            int e = q.back().second;
            ans = max(ans, e-s + 1);
            while(n--){
                auto idx = q.front().second - s;
                auto curr = q.front().first; q.pop();
                if(curr->left) q.push({curr->left, (idx<<1) + 1});
                if(curr->right) q.push({curr->right, (idx<<1) + 2});
            }
        }
        return ans;
    }
};