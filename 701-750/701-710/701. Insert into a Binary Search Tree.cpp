class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int k) {
        if(!root) return new TreeNode(k);
        TreeNode* curr = root;
        while(curr){
            if(curr->val < k){
                if(curr->right) curr = curr->right;
                else{ curr->right = new TreeNode(k); return root; }
            }else{
                if(curr->left) curr = curr->left;
                else{ curr->left = new TreeNode(k); return root; }
            }
        }
        return NULL;
    }
};