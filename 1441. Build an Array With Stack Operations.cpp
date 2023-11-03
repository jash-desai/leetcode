class Solution {
public:
    vector<string> buildArray(vector<int>& v, int k) {
        int n = v.size(); vector<bool> vis(k+1, 0);
        for(int x : v) vis[x] = 1;
        vector<string> ans;
        int curr = 0;
        for(int i=1; i<=k; i++){
            ans.push_back("Push");
            if(vis[i]){
                curr++;
                if(curr==n) break;
            }else{
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};