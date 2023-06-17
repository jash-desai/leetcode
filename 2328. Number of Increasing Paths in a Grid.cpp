#define vvi vector<vector<int>>
class Solution {
private:
    int mod = 1e9+7; int n; int m;
    // int dr[] = {-1,0,1,0}; int dc[] = {0,1,0,-1};
public:
    int solve(int i,int j, vvi&g, vvi&dp){
        if(i<0 or j<0 or i>=n or j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0;
        if(i+1 < n and g[i][j] < g[i+1][j]){
            a = solve(i+1, j, g, dp);
        }
        if(i-1>=0 and g[i][j] < g[i-1][j]){
            b = solve(i-1, j, g, dp);
        }
        if(j+1<m and g[i][j] < g[i][j+1]){
            c = solve(i, j+1, g, dp);
        }
        if(j-1>=0 and g[i][j] < g[i][j-1]){
            d = solve(i, j-1, g, dp);
        }
        return dp[i][j] = ((((a+b)%mod + c)%mod + d)%mod + 1)%mod;
    }
    int countPaths(vector<vector<int>>&v) {
        int i = 0, j = 0; n = v.size(), m = v[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    solve(i,j,v,dp);
                }
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};