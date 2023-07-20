class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&v) {
        int n = v.size();
        if(v[0][0] or v[n-1][n-1]) return -1;
        queue<pair<int,pair<int,int>>> q; q.push({1,{0,0}});
        vector<vector<bool>> vis(n, vector<bool>(n,0)); vis[0][0]=1;
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int d = q.front().first; q.pop();
            if(r==n-1 and c==n-1) return d;
            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){
                    int nr = r+i; int nc = c+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<n){
                        if(!vis[nr][nc] and v[nr][nc]==0){
                            q.push({d+1,{nr,nc}});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};