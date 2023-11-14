class Solution {
public:
    void flatten(TreeNode* root) {
        /* Recursive - 
        if(!(root)) return;
        if(!(root->left) and !(root->right)) return;
        if(!(root->right)){
            flatten(root->left);
            root->right = root->left; 
            root->left = NULL; return;
        }else if(!(root->left)){
            flatten(root->right); return;
        }else{
            TreeNode* rt = root->right;
            flatten(root->right);
            TreeNode* lf = root->left;
            flatten(root->left);
            root->right = lf; TreeNode* curr = lf;
            while(lf->right) lf = lf->right;
            lf->right = rt; root->left = NULL;
            return;
        } */
        /* Iterative - Stack 
        if(!root) return;
        stack<TreeNode*> st; st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
        */
        /* Iterative - O(1) Space */
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};