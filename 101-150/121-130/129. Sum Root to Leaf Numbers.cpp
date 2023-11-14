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
    vector<int> v;
    void rec(TreeNode* root, int curr){
        if(root->left == nullptr and root->right==nullptr){
            v.push_back(curr*10 + root->val);
            return;
        }else{
            if(root->left){
                int tl = curr*10 + root->val;
                rec(root->left, tl);
            }
            if(root->right){
                int tr = curr*10 + root->val;
                rec(root->right, tr);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        rec(root, 0);
        int ans=0;
        for(int x:v){
            cout << x << " ";
            ans+=x;
        }
        return ans;
    }
};