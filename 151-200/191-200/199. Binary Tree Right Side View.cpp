// /*
class Solution {
public:
    void rec(TreeNode* root, vector<int>&v, int lev){
        if(!root) return;
        if(lev==size(v)) v.push_back(root->val);
        rec(root->right,v,lev+1);
        rec(root->left,v,lev+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v; rec(root,v,0); return v;
    }
};
// */
/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans; queue<pair<TreeNode*, int>> q; map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int lvl = q.front().second; q.pop();
            // if(mp.find(lvl) == mp.end()) 
            mp[lvl] = curr->val;
            if(curr->left) q.push({curr->left, lvl+1});
            if(curr->right) q.push({curr->right, lvl+1});
        }
        for(auto x : mp) ans.push_back(x.second);
        return ans;
    }
};
*/