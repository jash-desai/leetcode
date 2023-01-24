class Solution {
public:
    bool isLeaf(TreeNode* root){
        return (!root -> left && !root -> right);
    }
    bool helper(TreeNode* root, int sum){
        if(!root) return false;
        sum -= root -> val;
        if(isLeaf(root) && sum == 0)
            return true;
        if(helper(root -> left , sum) || helper(root -> right , sum))
            return true;
        sum += root -> val;
        return false;   
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return helper(root , sum);
    }
};