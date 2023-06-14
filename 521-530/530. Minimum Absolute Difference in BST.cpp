class Solution {
private:
/* - O(N) SC: -

    void rec(TreeNode* root, vector<int>&v) {
        if(!root) return;
        rec(root -> left, v);
        v.push_back(root -> val);
        rec(root -> right, v);
    }
*/
//   - O(1) SC: -
    void rec(int&a, int&pr, TreeNode* root) {
        if(!root) return;
        rec(a, pr, root->left);
        if(pr != INT_MIN) a = min(a, abs(root->val - pr));
        pr = root->val;
        rec(a, pr, root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
/* - O(N) SC : -
        vector<int> v; int a = INT_MAX;
        rec(root, v);
        for (int i = 0; i < v.size()-1; i++) a = min(a, v[i+1] - v[i]);
        return a;
*/
        // O(1) SC :
        int a = INT_MAX, pr = INT_MIN;
        rec(a,pr,root);
        return a;
    }
};