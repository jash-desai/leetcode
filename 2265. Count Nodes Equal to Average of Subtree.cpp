class Solution {
    int ans;
private:
    array<int, 2> rec(TreeNode* root){
        if(!root) return {0,0};
        int sum = root->val;
        int cnt = 1;
        const auto &[subSum1, subCnt1] = rec(root->left);
        const auto &[subSum2, subCnt2] = rec(root->right);
        sum += (subSum1 + subSum2); cnt += (subCnt1 + subCnt2);
        if(root->val == (int)(sum/cnt)) ans++;
        return {sum, cnt};
    
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0; rec(root);
        return ans;
    }
};