class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans; unordered_map<int, TreeNode*> par;
        queue<TreeNode*> q; q.push(root); unordered_map<int, int> vis;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto top = q.front(); q.pop();
                if(top -> left){
                    par[top->left->val] = top;
                    q.push(top->left); 
                }
                if(top -> right){
                    par[top->right->val] = top;
                    q.push(top->right); 
                }
            }
        }
        q.push(target);
        while(k-- and !q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front(); q.pop();
                vis[curr->val] = 1;
                if(curr->left and !vis[curr->left->val]){
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right->val]){
                    q.push(curr->right);
                }
                if(par[curr->val] and !vis[par[curr->val] -> val]){
                    q.push(par[curr->val]);
                }
            }
        }
        while(!q.empty()){ ans.push_back(q.front()->val); q.pop(); }
        return ans;
    }
};