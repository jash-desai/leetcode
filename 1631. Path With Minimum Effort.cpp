class Solution {
public:
    int minimumEffortPath(vector<vector<int>>&v){
        int n=v.size(); int m=v[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        pq.push({0,{0,0}}); dis[0][0]=0;
        int dr[4] = {-1,0,1,0}; int dc[4] = {0,1,0,-1};
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int d = pq.top().first; pq.pop();
            if(r==n-1 and c==m-1) return d;
            for(int i=0; i<4; i++){
                int nr = r+dr[i]; int nc = c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    int nd = max(abs(v[r][c] - v[nr][nc]), d);
                    if(dis[nr][nc] > nd){
                        dis[nr][nc] = nd;
                        pq.push({dis[nr][nc], {nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};