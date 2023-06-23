class Solution {
private:
    // int rec(int n, int m, vector<vector<int>>&v, vector<vector<int>>&dp){
    //     if(n<=0 or m<=0) return 0;
    //     if(v[n-1][m-1] == 1) return 0;
    //     if(n==1 and m==1) return 1;
    //     if(dp[n][m] != -1) return dp[n][m];
    //     int ans1 = rec(n-1,m,v,dp);
    //     int ans2 = rec(n,m-1,v,dp);
    //     return dp[n][m] = (ans1+ans2);
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        /*
        // if(n==1 and m==1 and v[0][0]==0) return 1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return rec(n,m,v,dp);
        dp[1][1] = !(v[0][0]);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                if(v[i-1][j-1]==1) continue;
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = (ans1+ans2);
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1, 0), curr(m+1, 0);
        curr[1] = !(v[0][0]);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                if(v[i-1][j-1]!=0) continue;
                int ans1 = prev[j];
                int ans2 = curr[j-1];
                curr[j] = (ans1+ans2);
            }
            prev = curr;
            curr.assign(m+1, 0);
        }
        return prev[m];
    }
};