/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return 1;
        if(!(root->right) and !(root->left)) return 1;
        if(root->left and root->right){
            if(root->val == root->left->val + root->right->val){
                return (checkTree(root->left) and checkTree(root->right));
            }else{
                return 0;
            }
        }
        if(!root->left and root->right){
            return (root->val == root->right->val and checkTree(root->right));
        }
        return (root->val == root->left->val and checkTree(root->left));
    }
};