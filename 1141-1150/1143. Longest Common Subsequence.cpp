class Solution {
private:
    int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
        if(!n or !m) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1]==b[m-1]) return dp[n][m] = 1 + rec(a,b,n-1,m-1,dp);
        return dp[n][m] = max(rec(a,b,n,m-1,dp), rec(a,b,n-1,m,dp));
    }
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return rec(a,b,n,m,dp);
        */
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]); 
            }
            prev = curr;
        }
        return curr[m];
    }
};