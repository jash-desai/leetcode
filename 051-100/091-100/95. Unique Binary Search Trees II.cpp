class Solution {
    int n;
private:
    vector<TreeNode*> rec(int i, int j, vector<int>&v){
        if(i<0 or j>=n or i>j) return {NULL};
        vector<TreeNode*> ans;
        for(int k=i; k<=j; k++){
            vector<TreeNode*> ansLeft = rec(i, k-1, v);
            vector<TreeNode*> ansRight = rec(k+1, j, v);
            for(auto l : ansLeft){
                for(auto r : ansRight){
                    TreeNode* root = new TreeNode(v[k], l, r);
                    ans.push_back(root);
                }
            }
        } return ans;
    }
public:
    vector<TreeNode*> generateTrees(int N) {
        n = N; if(n==0) return {new TreeNode()};
        if(n==1) return {new TreeNode(1)};
        vector<int> v(n); for(int i=0; i<n; i++) v[i] = i+1;
        return rec(0,n-1, v);
    }
};