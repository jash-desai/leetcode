class Solution {
private: 
    void dfs(vector<vector<char>>&v, vector<vector<bool>>&vis, int i, int j){
        int n=v.size(), m=v[0].size();
        if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or v[i][j]=='X') return;
        vis[i][j]=1;
        int dr[4] = {-1,0,1,0}; int dc[4]={0,1,0,-1};
        for(int z=0; z<4; z++){
            dfs(v,vis,i+dr[z],j+dc[z]);
        }
    }
public:
    void solve(vector<vector<char>>&v) {
        int n=v.size(), m=v[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            if(!vis[i][0] and v[i][0]!='X') dfs(v,vis,i,0);
            if(!vis[i][m-1] and v[i][m-1]!='X') dfs(v,vis,i,m-1);
        }
        for(int j=0; j<m; j++){
            if(!vis[0][j] and v[0][j]!='X') dfs(v,vis,0,j);
            if(!vis[n-1][j] and v[n-1][j]!='X') dfs(v,vis,n-1,j);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and v[i][j]!='X') v[i][j]='X';
            }
        }
    }
};