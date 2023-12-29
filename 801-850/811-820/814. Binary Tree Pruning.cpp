/*
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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;      // base case
        root->left = pruneTree(root->left); // rec calls
        root->right = pruneTree(root->right);  // rec calls
        if(!root->right and !root->left and root->val != 1) return NULL;   // condition to implement in each call.
        
        // else return root
        return root;
    }
};