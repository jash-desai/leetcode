class Solution {
    int dirs[5] = {-1, 0, 1, 0, -1};
public:
    int nearestExit(vector<vector<char>>&v, vector<int>&pos) {
        int n = v.size(), m = v[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int sr = pos[0], sc = pos[1]; queue<array<int,3>> q;
        q.push({0, sr, sc});
        while(q.size()){
            auto [d, r, c] = q.front(); q.pop();
            if((c==0 or c==m-1) and (r!=sr or c!=sc)) return d;
            if((r==0 or r==n-1) and (r!=sr or c!=sc)) return d;
            for(int i=0; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    if(!vis[nr][nc] and v[nr][nc]=='.'){
                        q.push({d+1, nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        } return -1;
    }
};