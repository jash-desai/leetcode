class Solution{
private:
    int n; vector<vector<int>> dp;
    int rec(int i, int j, vector<vector<int>>&v){
        if(i<0 or i>=n or j<0 or j>=n) return INT_MAX;
        if(i==n-1) return dp[i][j] = v[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int ans1 = INT_MAX;
        if(i+1<n and j-1>=0 and dp[i+1][j-1] != -1) ans1 = dp[i+1][j-1];
        else ans1 = rec(i+1,j-1,v);
        if(ans1 != INT_MAX) ans1 += v[i][j];
        int ans2 = INT_MAX;
        if(i+1<n and dp[i+1][j] != -1) ans2 = dp[i+1][j];
        else ans2 = rec(i+1,j,v);
        if(ans2 != INT_MAX) ans2 += v[i][j];
        int ans3 = INT_MAX;
        if(i+1<n and j+1<n and dp[i+1][j+1] != -1) ans3 = dp[i+1][j+1];
        else ans3 = rec(i+1,j+1,v);
        if(ans3 != INT_MAX) ans3 += v[i][j];
        return dp[i][j] = min({ans1, ans2, ans3});
    }
public:
    int minFallingPathSum(vector<vector<int>>&v) {
        n = v.size(); dp.resize(n, vector<int>(n, -1));
        int ans = INT_MAX;
        /* memoization gives TLE on last TC
        for(int j=0; j<n; j++){
            int temp = rec(0,j,v);
            ans = min(ans, temp);
        }
        */
        for(int j=0; j<n; j++) dp[n-1][j] = v[n-1][j];
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(j==n-1){
                    int ans1 = v[i][j] + dp[i+1][j-1];
                    int ans2 = v[i][j] + dp[i+1][j];
                    dp[i][j] = min(ans1,ans2);
                }else if(j==0){
                    int ans2 = v[i][j] + dp[i+1][j];
                    int ans3 = v[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(ans2,ans3);
                }else{
                    int ans1 = v[i][j] + dp[i+1][j-1];
                    int ans2 = v[i][j] + dp[i+1][j];
                    int ans3 = v[i][j] + dp[i+1][j+1];
                    dp[i][j] = min({ans1, ans2, ans3});
                }
            }
        }
        for(int j=0; j<n; j++) ans = min(ans, dp[0][j]);
        return ans;
    }
};