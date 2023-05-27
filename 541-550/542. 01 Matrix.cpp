#define pii pair<int,int>
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&v) {
        int n=v.size(), m=v[0].size();
        vector<vector<int>> a(n, vector<int>(m,0));
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        queue<pair<pii,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==0){
                    q.push({{i,j},0});
                    // a[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int dr[4] = {-1,0,1,0}; int dc[4] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second; q.pop();
            a[r][c]=d;
            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0){
                    a[nr][nc]=d+1;
                    vis[nr][nc]=1;
                    q.push({{nr,nc}, d+1});
                }
            }
        }
        return a;
    }
};