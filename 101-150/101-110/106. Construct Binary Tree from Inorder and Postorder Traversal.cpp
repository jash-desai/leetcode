#define vi vector<int>
#define Node TreeNode
class Solution {
    unordered_map<int, int> mp;
private:
    Node* rec(vi&pos, int posSt, int posEn, vi&ino, int inoSt, int inoEn){
        if(posSt>posEn or inoSt>inoEn) return NULL;
        Node* root = new Node(pos[posEn]);
        int rootIdx = mp[root->val];
        int cnt = rootIdx - inoSt;
        root->left = rec(pos,posSt, posSt+cnt-1, ino, inoSt, rootIdx-1);
        root->right = rec(pos, posSt+cnt, posEn-1, ino, rootIdx+1, inoEn);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& pos) {
        mp.clear(); for(int i{0}; i<size(ino); i++) mp[ino[i]] = i;
        return rec(pos,0,size(pos)-1,ino,0,size(ino)-1);
    }
};