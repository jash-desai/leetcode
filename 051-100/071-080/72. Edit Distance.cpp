class Solution {
private:
/*
    vector<vector<int>> dp;
    int rec(string&a, string&b, int n, int m){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=INT_MAX) return dp[n][m];
        if(a[n-1]==b[m-1]) return dp[n][m] = rec(a,b,n-1,m-1);
        return dp[n][m] = 1 + min({rec(a,b,n-1,m-1), rec(a,b,n,m-1), rec(a,b,n-1,m)});
    }
    */
public:
    int minDistance(string a, string b) {
        int n = a.size(); int m = b.size();
        if(n==0) return m;
        if(m==0) return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        // dp.resize(n+1, vector<int>(m+1, INT_MAX));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
        // return rec(a,b,n,m);
    }
};