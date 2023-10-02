class Solution {
public:
    int minimumEffortPath(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        priority_queue<array<int, 3>> pq; pq.push({0, 0, 0});
        vector<vector<int>> dis(n, vector<int>(m, 1e9)); dis[0][0] = 0;
        while(pq.size()){
            auto [d, r, c] = pq.top(); pq.pop(); d = -d;
            if(r==n-1 and c==m-1) return d;
            for(int i=0; i<4; i++){
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    int nd = max(d, abs(v[r][c] - v[nr][nc]));
                    if(dis[nr][nc] > nd){
                        pq.push({-nd, nr, nc});
                        dis[nr][nc] = nd;
                    }
                }
            }
        }
        return -1;
    }
};
