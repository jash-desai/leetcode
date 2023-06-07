
class DSU {
    vector<int> rank, par;
public:
    DSU(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0; i<n+1; i++) par[i]=i;
    }
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u]=findPar(par[u]);
    }
    void unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu==pv) return;
        if(rank[pu] < rank[pv]) par[pu] = pv;
        else if(rank[pv] < rank[pu]) par[pv]=pu;
        else{
            par[pv] = pu; 
            rank[pu]++;
        }
        return;
    }
};
class Solution {
    void dfs(vector<int> adj[], vector<bool> &visited, int src){
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>&v) {
        // int len = arr.size();
        // if(len < n-1) return -1;
        // vector<int> adj[n];
        // for(auto v : arr){
        //     adj[v[0]].push_back(v[1]);
        //     adj[v[1]].push_back(v[0]);
        // }
        // vector<bool> visited(n, false);
        // int ans = 0;
        // for(int i=0; i<n; i++)
        // if(!visited[i]){
        //     dfs(adj, visited, i);
        //     ans++;
        // }
        // return ans - 1;
        DSU ds(n); int ee = 0; int cc=0;
        for(auto x:v){
            int u = x[0]; int v = x[1];
            if(ds.findPar(u) == ds.findPar(v)) ee++;
            else ds.unionByRank(u,v);
        }
        for(int i=0; i<n; i++){
            if(ds.findPar(i)==i) cc++;
        }
        int a = cc-1;
        if(ee>=a) return a;
        return -1;
    }
};


