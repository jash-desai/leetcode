class Solution {
    TreeNode* first, *prev, *mid, *last;
private:
    void ino(TreeNode* root){
        if(!root) return;
        ino(root->left);
        if(prev and root->val < prev->val){
            if(!first){
                first = prev;
                mid = root;
            }else{
                last = root;
            }
        }
        prev = root;
        ino(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        ino(root);
        if(first and last) swap(first->val, last->val);
        else if(first and mid) swap(first->val, mid->val);
        return;
    }
};