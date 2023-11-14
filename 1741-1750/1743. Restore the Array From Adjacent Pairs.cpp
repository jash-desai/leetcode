class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>&mat) {
        int n = mat.size(); n++;
        map<int, vector<int>> adj;
        for(auto&m : mat){
            int u = m[0], v = m[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        int curr = -1, par = -1; 
        for(auto&[a, b] : adj){
            if(b.size() == 1){
                par = curr = a;
                break;
            }
        }
        int idx = 0; ans[idx++] = curr;
        curr = adj[curr][0];
        while(idx<n){
            ans[idx++] = curr;
            if(idx==n) break;
            int prev = par; par = curr;
            if(adj[curr][0]!=prev) curr = adj[curr][0];
            else curr = adj[curr][1];
        }
        return ans;
    }
};