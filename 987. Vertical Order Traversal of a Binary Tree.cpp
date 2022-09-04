class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        
        vector<vector<int>> a;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            root=q.front().first;
            
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            m[x][y].insert(root->val);
            if(root->left) q.push({root->left,{x-1,y+1}});
            if(root->right) q.push({root->right,{x+1,y+1}});
        }
        for(auto x:m){
            vector<int> col;
            for(auto y:x.second){
                for(auto ele:y.second) col.push_back(ele);
            }
            a.push_back(col);
        }
        return a;
    }
};