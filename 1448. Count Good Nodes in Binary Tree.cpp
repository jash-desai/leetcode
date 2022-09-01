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
    int ans=0;
    void f(TreeNode* root,int maxi){
        if(!root) return;
        if(root->val>=maxi){
            ans++;
            maxi = root->val;
        }
        f(root->left,maxi);
        f(root->right,maxi);
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 1;
        f(root,root->val);
        return ans;
    }
};