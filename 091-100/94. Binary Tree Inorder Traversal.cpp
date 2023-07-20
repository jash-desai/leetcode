class Solution {
private:
    void rec(TreeNode* root, vector<int>&a){
        if(!root) return;
        if(root->left) rec(root->left,a);
        a.push_back(root->val);
        if(root->right) rec(root->right,a);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans; // rec(root, ans); return ans;
        stack<TreeNode*> st; st.push(root);
        // TreeNode* curr = root;
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->left){
                st.push(curr->left); 
                curr->left = NULL; continue;
            }else if(curr){
                ans.push_back(curr->val);
                st.pop();
            }
            if(curr->right){
                st.push(curr->right); 
                curr->right = NULL;
            }            
        }
        return ans;
    }
};