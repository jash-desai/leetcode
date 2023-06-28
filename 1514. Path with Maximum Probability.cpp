#define inf numeric_limits<double>::max()
#define vvi vector<vector<int>>
#define pii pair<int,double>
#define pdi pair<double,int>
#define prq priority_queue
#define vd vector<double>
class Solution {
public:
    double maxProbability(int n, vvi&edg, vd&probs, int s, int e) {
        vector<vector<pii>> adj(n);
        for(int i=0; i<edg.size(); i++){
            int u = edg[i][0], v = edg[i][1];
            double w = probs[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        prq<pdi, vector<pdi>> pq; pq.push({1,s});
        vector<double> prob(n,-1); prob[s]=1;
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(u==e) return d;
            for(auto [v, w] : adj[u]){
                if(prob[v] < prob[u]*w){
                    prob[v] = prob[u]*w;
                    pq.push({prob[v], v});
                }
            }
        }
        return 0;
    }
};