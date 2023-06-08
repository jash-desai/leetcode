class DSU {
public:
    vector<int> rank, par;
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
            par[pv] = pu; rank[pu]++;
        }
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>&v) {
        int n=v.size(); unordered_map<string,int> m;
        DSU ds(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<v[i].size(); j++){
                if(m.find(v[i][j]) == m.end()){
                    m.insert({v[i][j], i});
                }else{
                    ds.unionByRank(i, m[v[i][j]]);
                }
            }
        }
        vector<vector<string>> temp(n);
        for(auto x : m){
            string id = x.first;
            int idx = ds.findPar(x.second);
            temp[idx].push_back(id);
        }
        for(int i=0; i<n; i++){
            sort(temp[i].begin(), temp[i].end());
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(temp[i].size()==0) continue;
            vector<string> t = {v[i][0]};
            for(string s : temp[i]){
                t.push_back(s);
            }
            ans.push_back(t);
        }
        return ans;
    }
};