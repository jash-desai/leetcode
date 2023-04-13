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
    int maxl=0;
    void rec(TreeNode* root, vector<int>&v, int lev){
        if(!root) return;
        if(maxl < lev){
            v.push_back(root->val);
            maxl = lev;
        }
        rec(root->right,v,lev+1);
        rec(root->left,v,lev+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rec(root,v,1);
        return v;
    }
};