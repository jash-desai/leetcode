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
    void rec(TreeNode* root, int&k){
        if(root==nullptr) return;
        if(root->left){
            if(root->left->left==nullptr and root->left->right==nullptr){
                k += root->left->val;
                if(root->right) rec(root->right,k);
            }else{
                rec(root->left, k);
                if(root->right) rec(root->right,k);
            }
        }else if(root->right){
            rec(root->right, k);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int k = 0;
        rec(root,k);
        return k;
    }
};