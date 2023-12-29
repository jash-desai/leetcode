#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>&mat, int n, int s){
        vector<vector<pii>> adj(n+1);
        for(auto &m : mat){
            int u = m[0], v = m[1], w = m[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n+1, INT_MAX); dist[0]=dist[s]=0;
        set<pii> st; st.insert({0, s});
        while(!st.empty()){
            auto x = *st.begin();
            int u = x.second, d = x.first;
            st.erase(st.begin());
            for(pii p : adj[u]){
                int v = p.first, w = p.second;
                if(dist[v] > d+w){
                    dist[v] = d+w;
                    st.insert({d+w, v});
                }
            }
        }
        for(int &x : dist) if(x==INT_MAX) return -1;
        return *max_element(dist.begin(), dist.end());
    }
};