/* DFS Traversal :
class Solution {
private:
    void dfs(vector<vector<int>>&v, vector<vector<bool>>&vis, int r, int c){
        int n=v.size(), m=v[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0}; int dc[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int nr = r+dr[k], nc = c+dc[k];
            if(nr<n and nr>=0 and nc<m and nc>=0 and v[nr][nc] and !vis[nr][nc]){
                dfs(v,vis,nr,nc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>&v) {
        int n=v.size(), m=v[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0; i<n; i++){
            if(v[i][0] and !vis[i][0]) dfs(v,vis,i,0);
            if(v[i][m-1] and !vis[i][m-1]) dfs(v,vis,i,m-1);
        }
        for(int i=0; i<m; i++){
            if(v[0][i] and !vis[0][i]) dfs(v,vis,0,i);
            if(v[n-1][i] and !vis[n-1][i]) dfs(v,vis,n-1,i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==1 and !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};
*/
/* BFS Traversal : */
#define pii pair<int,int>
class Solution {
private:
    int dr[4]={-1,0,1,0}; int dc[4]={0,1,0,-1};
public:
    int numEnclaves(vector<vector<int>>&v){
        int n=v.size(), m=v[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pii> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!i or !j or i==n-1 or j==m-1){
                    if(v[i][j]){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr<n and nr>=0 and nc<m and nc>=0){
                    if(v[nr][nc] and !vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=1;    
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==1 and !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};
