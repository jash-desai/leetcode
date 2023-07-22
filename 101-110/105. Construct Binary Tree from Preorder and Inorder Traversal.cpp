#define vi vector<int>
class Solution {
    unordered_map<int, int> mp;
private:
    TreeNode* rec(vi&pre,int preSt,int preEn,vi&ino,int inoSt,int inoEn){
        if(preSt > preEn or inoSt > inoEn) return NULL;
        TreeNode* root = new TreeNode(pre[preSt]);
        int rootIdx = mp[root->val];
        int cntLeft = rootIdx - inoSt;
        root->left = rec(pre, preSt+1, preSt+cntLeft, ino, inoSt, rootIdx-1);
        root->right = rec(pre,preSt+cntLeft+1, preEn, ino, rootIdx+1, inoEn);
        return root;
    }
public:
    TreeNode* buildTree(vector<int> &pre, vector<int> &ino) {
        mp.clear(); for(int i{0}; i<size(ino); i++) mp[ino[i]]=i;
        return rec(pre, 0, size(pre)-1, ino, 0, size(ino)-1);
    }
};