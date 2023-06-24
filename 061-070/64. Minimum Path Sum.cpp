class Solution {
private:
    // int rec(int n, int m, vector<vector<int>>&v, vector<vector<int>>&dp){
    //     if(n<=0 or m<=0) return INT_MAX;
    //     if(n==1 and m==1) return v[0][0];
    //     if(dp[n][m] != -1) return dp[n][m];
    //     int ans1 = rec(n-1,m,v,dp);
    //     int ans2 = rec(n,m-1,v,dp);
    //     if(ans1 != INT_MAX) ans1 += v[n-1][m-1];
    //     if(ans2 != INT_MAX) ans2 += v[n-1][m-1];
    //     return dp[n][m] =  min(ans1, ans2);
    // }
public:
    int minPathSum(vector<vector<int>>&v) {
        int n = v.size(), m = v[0].size();
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        // return rec(n,m,v,dp);
        dp[1][1] = v[0][0];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                int ans1 = dp[i-1][j];
                if(ans1 != INT_MAX) ans1 += v[i-1][j-1];
                int ans2 = dp[i][j-1];
                if(ans2 != INT_MAX) ans2 += v[i-1][j-1];
                dp[i][j] = min(ans1, ans2);
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1, INT_MAX), curr(m+1, INT_MAX);
        curr[1] = v[0][0];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==1 and j==1) continue;
                int ans1 = prev[j];
                if(ans1 != INT_MAX) ans1 += v[i-1][j-1];
                int ans2 = curr[j-1];
                if(ans2 != INT_MAX) ans2 += v[i-1][j-1];
                curr[j] = min(ans1, ans2);
            }
            prev.insert(prev.begin(), curr.begin(), curr.end());
            curr.assign(m+1, INT_MAX);
        }
        return prev[m];
    }
};

/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
*/