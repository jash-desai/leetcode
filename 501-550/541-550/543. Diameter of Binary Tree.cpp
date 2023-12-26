class Solution {
private:
    int rec(TreeNode* root, int&ans){
        if(!root) return 0;
        int lh = rec(root->left, ans);
        int rh = rec(root->right, ans);
        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // int ans{0}; rec(root,ans); return ans;

        // slow and space consuming - 
        stack<TreeNode*> st; st.push(root);
        unordered_map<TreeNode*, int> mp; int ans{0};
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->left and !mp.count(curr->left)){
                st.push(curr->left);
            }
            else if(curr->right and !mp.count(curr->right)){
                st.push(curr->right);
            }
            else{
                st.pop();
                int ld = mp[curr->left], rd = mp[curr->right];
                mp[curr] = 1 + max(ld, rd);
                ans = max(ans, ld + rd);
            }
        }
        return ans;
    }
};
