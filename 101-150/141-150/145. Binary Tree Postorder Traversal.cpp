class Solution {
private:
    void rec(TreeNode* root, vector<int>&a){
        if(!root) return;
        if(root->left) rec(root->left,a);
        if(root->right) rec(root->right,a);
        a.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans; // rec(root, ans); return ans;
        // 1 stack approach;
        stack<TreeNode*> st; st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->left){
                st.push(curr->left); 
                curr->left = NULL;
            }else if(curr->right){
                st.push(curr->right); 
                curr->right = NULL;
            }else{
                ans.push_back(curr->val);
                st.pop();
            }
        }
        return ans;
    }
};