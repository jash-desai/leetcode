class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>&re, vector<vector<int>>&be) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &m : re) adj[m[0]].push_back({m[1], 0});
        for(auto &m : be) adj[m[0]].push_back({m[1], 1});
        vector<int> dis(n, -1); queue<array<int, 3>> q;
        vector<vector<bool>> vis(n, vector<bool>(2));
        q.push({0, 0, -1}); vis[0][0] = vis[0][1] = true; dis[0] = 0;
        while(!q.empty()) {
            auto [u,d,f] = q.front(); q.pop();
            for (auto& [v, c] : adj[u]) {
                if (!vis[v][c] and c != f) {
                    vis[v][c] = true;
                    q.push({v, 1 + d, c});
                    if (dis[v] == -1) dis[v] = 1 + d;
                }
            }
        }
        return dis;
    }
};