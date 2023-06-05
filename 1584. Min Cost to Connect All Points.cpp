#define pii pair<int,int>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>&v) {
        int n=v.size();
        vector<pii> dis[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int d = abs(v[i][0]-v[j][0]) + abs(v[i][1]-v[j][1]);
                dis[i].push_back({j,d});
                dis[j].push_back({i,d});
            }
        }
        vector<bool> vis(n,0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,0}); int a=0;
        while(!pq.empty()){
            int d = pq.top().first; 
            int u = pq.top().second; 
            pq.pop(); 
            if(vis[u]) continue;
            a+=d; vis[u]=1;
            for(auto x : dis[u]){
                int v = x.first; int w = x.second;
                if(!vis[v]) pq.push({w,v});
            }
        }
        return a;
    }
};