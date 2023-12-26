#define pii pair<int,int>
class Solution {
    int dirs[5] = {-1,0,1,0,-1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        queue<pair<pii,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second; q.pop();
            ans[r][c]=d;
            for(int i=0; i<4; i++){
                int nr = r+dirs[i], nc = c+dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc]){
                    q.push({{nr,nc}, d+1});
                    vis[nr][nc]=1;
                }
            }
        } return ans;
    }
};