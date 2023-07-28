class BSTIterator {
    stack<TreeNode*> st;
private:
    void pushLeft(TreeNode* root){
        for(; root; st.push(root), root = root->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top(); st.pop();
        pushLeft(curr->right); return curr->val;
    }
    
    bool hasNext() {
        return !(st.empty());
    }
};