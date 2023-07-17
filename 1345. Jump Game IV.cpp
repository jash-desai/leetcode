class Solution {
public:
    int minJumps(vector<int>& arr){
        int n = size(arr); unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) mp[arr[i]].push_back(i);
        queue<int> q; vector<bool> vis(n, false); 
        q.push(0); vis[0] = true; int steps = 0;
        while(!q.empty()){
            int sz = size(q);
            while(sz--){
                int idx = q.front(); q.pop();
                if(idx == n-1) return steps;
                // condition 1 :
                if(idx+1 < n and !vis[idx+1]){
                    vis[idx+1] = true;
                    q.push(idx+1);
                }
                // condition 2 :
                if(idx-1 >= 0 and !vis[idx-1]){
                    vis[idx-1] = true;
                    q.push(idx-1);
                }
                // condition 3 :
                for(int i : mp[arr[idx]]){
                    if(!vis[i]){
                        vis[i] = true; 
                        q.push(i);
                    }
                }
                mp[arr[idx]].clear();
            }
            steps++;
        }
        return -1;
    }
};