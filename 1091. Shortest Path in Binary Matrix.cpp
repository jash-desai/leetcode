class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&v) {
        int n=v.size(); vector<vector<bool>> vis(n, vector<bool>(n,0));
        if(v[0][0]==1 or v[n-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1}); vis[0][0]=1;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second; q.pop();
            if(r==n-1 and c==n-1) return d;
            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){
                    int nr = r+i; int nc = c+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<n){
                        if(v[nr][nc]==0 and !vis[nr][nc]){
                            q.push({{nr,nc},d+1});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};