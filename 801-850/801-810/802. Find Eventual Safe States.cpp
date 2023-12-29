#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    bool dfs(int src, vi&vis, vi&pathVis, vvi&graph, vi&ans){
        vis[src]=1; pathVis[src]=1;
        for(auto child: graph[src]){
            if(!vis[child]){
                if(dfs(child, vis,pathVis, graph,ans)){
                    ans[src]=0;
                    return true;
                }
            }else if(pathVis[child]){
                ans[src]=0;
                return true;
            }
        }
        pathVis[src]=0; ans[src]=-1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vi vis(size(graph),0), ans(size(graph),0), pathVis(size(graph),0);
        for(int i=0;i<size(graph);i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph,ans);
            }
        }
        vector<int> res;
        for(int i=0; i<ans.size();i++){
            if(ans[i]==-1) res.push_back(i);
        }
        return res;
    }
};