class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        queue<array<int,2>> q1, q2; int dirs[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> vis1(n, vector<int>(m, 0)), vis2(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            q1.push({i,0}); vis1[i][0] = 1;
            q2.push({i,m-1}); vis2[i][m-1] = 1;
        }
        for(int j=0; j<m; j++){
            q1.push({0,j}); vis1[0][j] = 1;
            q2.push({n-1,j}); vis2[n-1][j] = 1;
        }
        while(q1.size()){
            auto [r,c] = q1.front(); q1.pop();
            for(int i=0; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis1[nr][nc]){
                    if(v[nr][nc] >= v[r][c]){
                        vis1[nr][nc] = 1;
                        q1.push({nr, nc});
                    }
                }
            }
        }
        while(q2.size()){
            auto [r,c] = q2.front(); q2.pop();
            for(int i=0; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis2[nr][nc]){
                    if(v[nr][nc] >= v[r][c]){
                        vis2[nr][nc] = 1;
                        q2.push({nr, nc});
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis1[i][j] and vis2[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};