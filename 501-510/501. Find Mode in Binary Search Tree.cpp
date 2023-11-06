class Solution {
    unordered_map<int, int> mp; int mx;
private:
    void rec(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        mx = max(mx, mp[root->val]);
        rec(root->left);
        rec(root->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        mp.clear(); vector<int> ans; //unordered_set<int> st;
        mx = 0;  rec(root);
        for(auto&[val, freq] : mp){
            if(freq == mx){
                ans.push_back(val);
            }
        }
        return ans;
    }
};