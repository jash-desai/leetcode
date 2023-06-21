class Solution {
public:
    int l=0, r=0, d=0;
    void Depth(TreeNode *R, int cur, int &ret){
        if(R==NULL) return;
        if(cur>ret) ret=cur;
        Depth(R->left, cur+1, ret);
        Depth(R->right, cur+1, ret);
    }
    void Left(TreeNode *R, int cur, int & ret){
        if(R==NULL) return;
        if(cur>ret) ret=cur;
        Left(R->left,cur+1,ret);
        Left(R->right, cur-1,ret);
    }
    void Right(TreeNode *R, int cur, int & ret){
        if(R==NULL) return;
        if(cur>ret) ret=cur;
        Right(R->right,cur+1,ret);
        Right(R->left, cur-1,ret);
    }
    void Make(TreeNode *R, int pos, int d, vector<vector<vector<int>>> &Ret){
        if(R==NULL) return;   
        Ret[pos+l][d].push_back(R->val);
        Make(R->left,pos-1, d+1,Ret);
        Make(R->right,pos+1,d+1,Ret);
    }
    vector<vector<int>> verticalTraversal(TreeNode* R){
        Left(R,0,l);
        Right(R,0,r);
        Depth(R,1,d);
        vector<vector<int>> ret(l+r+1);
        vector<vector<vector<int>>> Ret(l+r+1, vector<vector<int>>(d));
        Make(R,0,0,Ret);
        for(int i=0;i<d;i++){
            for(int j=0;j<l+r+1;j++){
                sort(Ret[j][i].begin(), Ret[j][i].end());
            }
        }
        for(int i=0;i<d;i++){
            for(int j=0;j<l+r+1;j++){
                for(int c:Ret[j][i]){
                    ret[j].push_back(c);
                }
            }
        }
        return(ret);
    }
};

// high runtime
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,map<int,multiset<int>>> m;
        
//         vector<vector<int>> a;
        
//         queue<pair<TreeNode*,pair<int,int>>> q;
//         q.push({root,{0,0}});
        
//         while(!q.empty()){
//             root=q.front().first;
            
//             int x=q.front().second.first;
//             int y=q.front().second.second;
//             q.pop();
//             m[x][y].insert(root->val);
//             if(root->left) q.push({root->left,{x-1,y+1}});
//             if(root->right) q.push({root->right,{x+1,y+1}});
//         }
//         for(auto x:m){
//             vector<int> col;
//             for(auto y:x.second){
//                 for(auto ele:y.second) col.push_back(ele);
//             }
//             a.push_back(col);
//         }
//         return a;
//     }
// };