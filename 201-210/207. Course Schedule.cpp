#define pii pair<int,int>
class Solution {
private:
    bool dfs(vector<vector<int>>&adj,vector<bool>&vis,unordered_set<int>&s, int u){
        vis[u]=1; s.insert(u);
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(adj,vis,s,v)) return 1;
            }else if(vis[v] and s.count(v)) return 1;
        }
        s.erase(u);
        return 0;
    }
public:
    bool canFinish(int V, vector<vector<int>>&m){
        vector<vector<int>> adj(V);
        for(auto &v:m) adj[v[0]].push_back(v[1]);
        vector<bool> vis(V,0); unordered_set<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(adj,vis,s,i)) return 0;
            }
        }
        return 1;
    }
};