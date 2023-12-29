class Solution {
public:
    int orangesRotting(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 2){
                    q.push({{i,j}, 0}); vis[i][j] = 1;
                }
            }
        } int ans = 0;
        int dr[4] = {-1, 0, 1, 0}; int dc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second; q.pop();
            ans = max(ans, t);
            for(int i=0; i<4; i++){
                int nr = r + dr[i]; int nc = c + dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    if(!vis[nr][nc] and v[nr][nc]==1){
                        q.push({{nr, nc}, t+1});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and v[i][j] != 0) return -1;
            }
        }
        return ans;
    }
};