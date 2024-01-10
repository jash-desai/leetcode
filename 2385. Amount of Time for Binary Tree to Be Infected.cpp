class Solution {
public:
    int amountOfTime(TreeNode* root, int k) {
        map<int, TreeNode*> mp; queue<TreeNode*> q; q.push(root);
        TreeNode* node = NULL; mp[root->val] = NULL;
        while(q.size()){
            auto curr = q.front(); q.pop();
            if(curr->val == k) node = curr;
            if(curr->left){
                mp[curr->left->val] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right->val] = curr;
                q.push(curr->right);
            }
        }
        unordered_set<TreeNode*> vis; int ans{0};
        queue<pair<TreeNode*, int>> qp; qp.push({node, 0});
        vis.insert(node);
        while(qp.size()){
            auto [curr, t] = qp.front(); qp.pop();
            ans = max(ans, t);
            if(curr->left and !vis.count(curr->left)){
                vis.insert(curr->left);
                qp.push({curr->left, t+1});
            }
            if(curr->right and !vis.count(curr->right)){
                vis.insert(curr->right);
                qp.push({curr->right, t+1});
            }
            if(mp[curr->val] and !vis.count(mp[curr->val])){
                vis.insert(mp[curr->val]);
                qp.push({mp[curr->val], t+1});
            }
        }
        return ans;
    }
};