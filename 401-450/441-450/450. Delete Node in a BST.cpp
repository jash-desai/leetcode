class Solution {
private:
    TreeNode* findLast(TreeNode* root){
        if(!root->right) return root;
        // return findLast(root->right); // recursive way
        while(root->right) root = root->right; // iterative way
        return root;
    }
    TreeNode* del(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* rightNode = root->right;
        TreeNode* lastRight = findLast(root->left);
        lastRight->right = rightNode;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(!root) return root;
        if(root->val == k) return del(root);
        TreeNode* newRoot = root;
        while(root){
            if(root->val > k){
                if(root->left and root->left->val == k){
                    root->left = del(root->left); break;
                }else root = root->left;
            }else{
                if(root->right and root->right->val == k){
                    root->right = del(root->right); break;
                }else root = root->right;
            }
        }
        return newRoot;
    }
};