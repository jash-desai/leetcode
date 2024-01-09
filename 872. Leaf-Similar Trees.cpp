class Solution {
    vector<int> ans;
private:
    void rec(TreeNode* root){
        if(!root) return;
        if(!(root->left) and !(root->right)){
            ans.push_back(root->val);
            return;
        }
        if(root->left) rec(root->left);
        if(root->right) rec(root->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        rec(root1); vector<int> ans1 = ans;
        ans.clear(); rec(root2); 
        // vector<int> ans2 = ans;
        // if(ans1.size() != ans2.size()) return 0;
        // for(int i=0; i<ans1.size(); i++){
        //     if(ans1[i] != ans2[i]) return 0;
        // }
        // return 1;
        return(ans==ans1);
    }
};