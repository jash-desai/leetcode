class Solution {
public:
    TreeNode* rec(int start,int end,vector<int> &nums){
    if(start>end) return NULL;

    int mid=start+(end-start)/2;
    TreeNode* node=new TreeNode(nums[mid]);        
    node->left=rec(start,mid-1,nums);              
    node->right=rec(mid+1,end,nums);
    return node;
    }
    TreeNode* sortedArrayToBST(vector<int>&v){
        int start=0;
        int end=v.size()-1;
        TreeNode* root=rec(start,end,v);
        return root;
    }
};