class Solution {
private:
    void dfs( vector<vector<int>>&adj,vector<bool>&vis,int u){
        vis[u]=1;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>&m) {
        int n=m.size(); vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(m[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,0); int c=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,vis,i); c++;
            }
        }
        return c;
    }
};