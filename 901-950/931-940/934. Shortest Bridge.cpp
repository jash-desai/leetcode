class Solution {
    int dirs[5] = {-1, 0, 1, 0, -1};
public:
    int shortestBridge(vector<vector<int>>&v) {
        int n = v.size(); queue<pair<int,int>> q; int sr, sc;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX)); 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]){
                    sr = i, sc = j;
                    break;
                }
            }
        }
        q.push({sr, sc}); v[sr][sc] = 2; int ans = n;
        while(q.size()){
            auto [r,c] = q.front(); q.pop();
            for(int i{0}; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<n){
                    if(v[nr][nc] == 1){
                        q.push({nr, nc}); v[nr][nc] = 2;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]==1) q.push({i,j}), dis[i][j] = 0;
            }
        }
        while(q.size()){
            auto [r,c] = q.front(); q.pop();
            for(int i{0}; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<n){
                    if(v[nr][nc] != 1 and dis[nr][nc] > 1 + dis[r][c]){
                        q.push({nr, nc}); 
                        dis[nr][nc] = 1 + dis[r][c];
                    }
                }
            }
            if(v[r][c] == 2) ans = min(ans, dis[r][c]);
        }
        return ans-1;
    }
};