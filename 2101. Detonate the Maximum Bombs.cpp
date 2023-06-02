#define ll long long int
class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int u, int&c){
        vis[u]=1; c++;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(adj,vis,v,c);
            }
        }
        return;
    }
public:
    int maximumDetonation(vector<vector<int>>&v) {
        int n=v.size(); vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ll x = abs(v[i][0]-v[j][0]);
                ll y = abs(v[i][1]-v[j][1]);
                ll r = abs(v[i][2]);
                if((x*x)+(y*y) <= (r*r)) adj[i].push_back(j);
            }
        }
        int a = INT_MIN;
        for(int i=0; i<n; i++){
            vector<bool> vis(n,0); int c=0;
            if(!vis[i]){
                dfs(adj,vis,i,c);
                a = max(a,c);
            }
        }
        return a;
    }
};