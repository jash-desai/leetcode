// /* 
class DSU{
    public:
    vector<int> par, size;
    DSU(int n){
        par.resize(n); for(int i{0}; i<n; i++) par[i]=i;
        size.resize(n, 0);
    }
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    void unionBySize(int u, int v){ 
        int pu = findPar(u); int pv = findPar(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){
            par[pu] = pv; size[pv] += size[pu];
        }else{
            par[pv] = pu; size[pu] += size[pv];
        }
        return;
    } 
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size(), ans = 0;
        DSU ds((n*m)); int dirs[5] = {-1, 0, 1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]){
                    ds.size[(i*m)+j] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!v[i][j]) continue;
                int u = (i*m) + j;
                for(int k=0; k<4; k++){
                    int nr = i + dirs[k], nc = j + dirs[k+1];
                    if(nr>=0 and nr<n and nc>=0 and nc<m){
                        int nu = (nr*m) + nc;
                        if(v[nr][nc]){
                            ds.unionBySize(u, nu);
                        }
                    }
                }
            }
        } 
        //int ans = 0;
        for(int i=0; i<n*m; i++) if(ds.par[i]==i and ds.size[i]) cout << ds.size[i] << " ";
        for(int i=0; i<n*m; i++){
            if(ds.par[i]==i){
                ans = max(ans, ds.size[i]);
            }
        }
        return ans;
    }
};
// */
/*
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size(),c=grid[0].size();
        cout << r*c << '\n';
        vector<vector<bool>> vis(r,vector(c,false));
        int dir_x[]={0,0,1,-1};
        int dir_y[]={1,-1,0,0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0 || vis[i][j]) continue;
                queue<pair<int,int>> q;
                int island=0;
                q.push({i,j}); vis[i][j]=true;
                while(!q.empty()){
                    auto front=q.front(); q.pop();
                    island++;
                    for(int d=0;d<4;d++){
                        int qr= front.first + dir_x[d];
                        int qc= front.second + dir_y[d];
                        if(qr<0 || qr>=r || qc<0 || qc>=c){
                            continue;
                        }
                        if(grid[qr][qc]==0) continue;
                        if(vis[qr][qc]) continue;
                        q.push({qr,qc});
                        vis[qr][qc]=true;
                    }
                }
                ans=max(ans,island);
            }
        }
        return ans;
    }
};
*/