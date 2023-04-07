class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int ni=i+dr[k],nj=j+dc[k];
            if(ni>=m or ni<0 or nj>=n or nj<0 or grid[ni][nj]==0) continue;
            dfs(ni,nj,grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]) dfs(i,0,grid);
            if(grid[i][n-1]) dfs(i,n-1,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]) dfs(0,i,grid);
            if(grid[m-1][i]) dfs(m-1,i,grid);
        }
        int ans=0;
        for(auto &i : grid){
            for(int &j : i){
                if(j) ans++;
            }
        }
        return ans;
    }
};