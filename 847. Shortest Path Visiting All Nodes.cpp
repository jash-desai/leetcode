class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all_visited = (1 << n) - 1;
        queue<array<int, 3>> q; unordered_set<int> vis;
        // q --> {mask, node, dist};
        for(int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0});
            vis.insert((1 << i) * 16 + i);
        }
        while (!q.empty()) {
            auto [mask, node, dist] = q.front(); q.pop();   
            if (mask == all_visited) return dist;
            for (int neighbor : graph[node]) {
                int new_mask = mask | (1 << neighbor);
                int hash_value = new_mask * 16 + neighbor;
                if (!vis.count(hash_value)) {
                    vis.insert(hash_value);
                    q.push({new_mask, neighbor, dist + 1});
                }
            }
        }
        
        return -1;
    }
};