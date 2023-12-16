class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>&m) {
        vector<int> a; vector<int> ind(V,0);
        vector<int> adj[V];
        for(auto &v:m){
            adj[v[1]].push_back(v[0]);
        }
        for(int i=0; i<V; i++){
            for(int u:adj[i]){
                ind[u]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(ind[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop(); a.push_back(u);
            for(int v:adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v); 
                }
            }
        }
        vector<int> t;
        // reverse(a.begin(), a.end());
        return a.size()==V ? a : t;
    }
};