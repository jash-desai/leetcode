class Solution {
private:
    // int rec(int n, int m, vector<vector<int>>&dp){
    //     if(n<=0 or m<=0) return 0;
    //     if(n==1 and m==1) return 1;
    //     if(dp[n][m] != -1) return dp[n][m];
    //     int ans1 = rec(n-1,m,dp);
    //     int ans2 = rec(n,m-1,dp);
    //     return dp[n][m] = (ans1+ans2);
    // }
public:
    int uniquePaths(int m, int n){
        swap(n,m); 
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return rec(n,m,dp);
        dp[1][1] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = (ans1+ans2);
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1,0), curr(m+1,0);
        curr[1]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                int ans1 = prev[j];
                int ans2 = curr[j-1];
                curr[j] = (ans1+ans2);
            }
            prev=curr;
        }
        return prev[m];
        /* Math - PnC
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        for (int i = 1; i <= r; i++){
            res = res * (N - r + i) / i;
        }
        return (int)res;
        */
    }
};