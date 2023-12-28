class Solution {
private:
    /* 
    int rec(vector<vector<int>>&v, int idx, int k, vector<vector<int>>&dp){
        if(idx==v.size()) return 0;
        if(dp[idx][k+1] != -1) return dp[idx][k+1];
        if(k==-1 or v[idx][0] > v[k][1]){
            int ans1 = rec(v,idx+1,k,dp);
            int ans2 = 1 + rec(v,idx+1,idx,dp);
            return dp[idx][k+1] = max(ans1, ans2);
        }
        return dp[idx][k+1] = rec(v,idx+1,k,dp);
    }
    */
public:
    int findLongestChain(vector<vector<int>>&v) {
        /* sort(v.begin(), v.end()); int n = v.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return rec(v,0,-1,dp);
        */ /*
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int k=-1; k<n; k++){
                if(k==-1 or v[i][0] > v[k][1]){
                    int ans1 = dp[i+1][k+1];
                    int ans2 = 1 + dp[i+1][i+1];
                    dp[i][k+1] = max(ans1, ans2);
                }else dp[i][k+1] = dp[i+1][k+1];
            }
        } return dp[0][0];
        */ /*
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int k=-1; k<n; k++){
                if(k==-1 or v[i][0] > v[k][1]){
                    int ans1 = prev[k+1];
                    int ans2 = 1 + prev[i+1];
                    curr[k+1] = max(ans1, ans2);
                }else curr[k+1] = prev[k+1];
            }
            prev = curr;
        } return prev[0];
        */
        int n = v.size(), k{-1}, ans{0};
        sort(begin(v), end(v), [&](const auto&a, const auto &b){
            return a[1] < b[1];
        });
        for(int i=0; i<n; i++){
            if(k==-1 or v[i][0]>v[k][1]) ans++, k=i;
        }
        return ans;
    }
};
