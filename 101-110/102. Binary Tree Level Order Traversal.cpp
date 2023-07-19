class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            vector<int> temp; int sz = q.size();
            while(sz--){
                TreeNode* curr = q.front(); q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};