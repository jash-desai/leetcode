#define pii pair<long long,long long>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>&m){
        int mod = (1e9+7);
        vector<vector<pii>> adj(n);
        for(auto x:m){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0,0});
        vector<long long> time(n,LONG_MAX); time[0]=0;
        vector<long long> way(n,0); way[0]=1;
        while(!pq.empty()){
            long long t = pq.top().first;
            long long u = pq.top().second;
            pq.pop();
            for(auto x : adj[u]){
                long long v = x.first; long long w = x.second;
                if(time[v]==(t+w)){
                    way[v] = ((way[v]%mod + way[u])%mod)%mod;
                }else if(time[v]>(t+w)){
                    time[v]=(t+w); 
                    pq.push({time[v],v});
                    way[v] = way[u];
                }
            }
        }
        return way[n-1]%mod;
    }
};