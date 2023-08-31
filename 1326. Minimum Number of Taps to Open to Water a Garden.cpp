class Solution {
public:
    int minTaps(int n, vector<int>&v) {
        vector<int> dp(n+1, 1e9); dp[0]=0;
        for(int i=0; i<=n; i++){
            int s = max(0, i-v[i]), e = min(n, i+v[i]);
            for(int j=s; j<=e; j++){
                if(dp[j] == 1e9) continue;
                dp[e] = min(dp[e], 1 + dp[j]);
            }
        }
        return dp[n]==1e9 ? -1 : dp[n];
    }
};