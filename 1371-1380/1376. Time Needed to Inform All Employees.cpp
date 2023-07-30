class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>&v, vector<int>&t){
        vector<vector<int>> adj(n); int a = t[h];
        for(int i=0; i<n; i++){
            if(v[i]!=-1) adj[v[i]].push_back(i);
        }
        vector<int> dis(n,0); dis[h]=0; queue<int> q; q.push(h);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                dis[v]=dis[u]+t[u]; a = max(a,dis[v]); q.push(v);
            }
        }
        return a;
    }
};