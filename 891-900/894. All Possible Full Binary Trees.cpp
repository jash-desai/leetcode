#define vn vector<TreeNode*>
#define Node TreeNode
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n%2)) return {};
        if(n == 1) return { new TreeNode() };
        vn ans; int rem = n-1;
        for(int lft{1}; lft<=rem; lft+=2){
            int rght = rem - lft;
            vn cntL = allPossibleFBT(lft), cntR = allPossibleFBT(rght);
            for(int i{0}; i<size(cntL); i++){
                for(int j{0}; j<size(cntR); j++){
                    Node* root = new TreeNode();
                    root->left = cntL[i]; root->right = cntR[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};