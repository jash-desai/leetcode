class Solution {
private:
    int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
        if(n<0 or m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(a[n]==b[m]) return dp[n][m] = (1 + rec(a,b,n-1,m-1,dp));
        return dp[n][m] = max(rec(a,b,n-1,m,dp), rec(a,b,n,m-1,dp));
    }
public:
    int longestCommonSubsequence(string&a, string&b) {
        int n = a.size(), m=b.size();
        if(n==0 or m==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // return rec(a,b,n-1,m-1,dp);
        for(int i=0; i<n; i++) dp[i][0]=0;
        for(int i=0; i<m; i++) dp[0][i]=0;
        int i=1, j=1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};