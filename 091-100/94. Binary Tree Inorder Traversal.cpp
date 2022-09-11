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
    void rec(TreeNode* root, vector<int>&a){
        if(!root) return;
        if(root->left) rec(root->left,a);
        a.push_back(root->val);
        if(root->right) rec(root->right,a);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        rec(root,a);
        return a;
    }
};