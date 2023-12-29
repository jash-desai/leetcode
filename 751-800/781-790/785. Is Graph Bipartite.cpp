/* BFS Approach - 
class Solution {
public:
    bool isBipartite(vector<vector<int>>&m) {
        int n = m.size();
        vector<int> vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                queue<int> q; vis[i] = 0; q.push(i);
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    for(int v : m[u]){
                        if(vis[v] == vis[u]) return false;
                        if(vis[v] == -1){
                            vis[v] = 1-vis[u];
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
};
*/
/* DFS Approach */
class Solution {
private:
    bool dfs(vector<vector<int>>&m, vector<int>&vis,int u, int k){
        vis[u]=k;
        for(int v:m[u]){
            if(vis[u]==vis[v]) return 0;
            if(vis[v]==-1){
                if(!dfs(m,vis,v,1-k)) return 0;
            }
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>&m) {
        int n = m.size(); vector<int> vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!dfs(m,vis,i,0)) return 0;
            }
        }
        return 1;
    }
};