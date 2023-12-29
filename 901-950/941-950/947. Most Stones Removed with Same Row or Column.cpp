class DSU {
public:
    vector<int> rank, par, size;
    DSU(int n){
        rank.resize(n+1,0); size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0; i<n+1; i++) par[i]=i;
    }
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u]=findPar(par[u]);
    }
    void unionByRank(int u, int v){
        int pu = findPar(u); int pv = findPar(v);
        if(pu==pv) return;
        if(rank[pu] < rank[pv]) par[pu] = pv;
        else if(rank[pv] < rank[pu]) par[pv]=pu;
        else{
            par[pv] = pu; rank[pu]++;
        }
        return;
    }
    void unionBySize(int u, int v){
        int pu = findPar(u); int pv = findPar(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){ 
            par[pu] = pv;
            size[pv] += size[pu];
        }else{
            par[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>&v){
        int n=INT_MIN, m=INT_MIN;
        for(auto x : v){
            n = max(n,x[0]);
            m = max(m,x[1]);
        }
        DSU ds(n+m+1); unordered_map<int,bool> mp;
        for(auto x : v){
            int r = x[0]; int c = n+x[1]+1;
            ds.unionBySize(r,c);
            mp[r]=1, mp[c]=1;
        }
        int c=0;
        for(auto x : mp){
            if(ds.findPar(x.first) == x.first) c++;
        }
        return v.size() - c;
    }
};