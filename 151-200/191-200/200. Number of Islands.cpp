class Solution {
public:
    void dfs(vector<vector<char>>&v, int i,int j){
        int n=v.size(), m=v[0].size();
        if(i<0 or j<0 or i>=n or j>=m or v[i][j]=='0') return;
        v[i][j]='0';
        dfs(v,i-1,j); dfs(v,i+1,j);
        dfs(v,i,j-1); dfs(v,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    ans++; dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};