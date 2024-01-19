/* Kahn's Algorithm
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& mat, vector<int>& time) {
        vector<vector<int>> adj(n); vector<int> ind(n, 0);
        for(auto &m : mat){
            int u = m[0], v = m[1]; u--, v--;
            adj[u].push_back(v); ind[v]++;
        }
        queue<int> q; vector<int> maxTime = vector(n, 0);
        for(int i=0; i<n; i++){
            if(ind[i]==0) q.push(i), maxTime[i] = time[i];
        }
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);
                ind[v]--;
                if(ind[v]==0) q.push(v);
            }
        }
        return *max_element(begin(maxTime), end(maxTime));
    }
};
*/

class Solution {
    vector<vector<int>> adj; 
    vector<int> dp; vector<int> time;
private:
    int rec(int u){
        if(adj[u].empty()) return time[u];
        if(dp[u] != -1) return dp[u];
        for(int v: adj[u]) dp[u] = max(dp[u], rec(v));
        return (dp[u] += time[u]);
    }
public:
    int minimumTime(int n, vector<vector<int>>& mat, vector<int>& time) {
        adj.resize(n); this->time = time;
        for(auto &m : mat){
            int u = m[0], v = m[1]; u--, v--;
            adj[u].push_back(v);
        }
        dp = vector(n, -1); int ans = 0;
        for(int i = 0; i<n; i++) ans = max(ans, rec(i));
        return ans;
    }  
};
