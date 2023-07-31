class Solution {
private:
    /* int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
        if(n==0){
            int ans{0};
            for(char c : b.substr(0,m)) ans += c;
            return dp[n][m] = ans;
        }
        if(m==0){
            int ans{0};
            for(char c : a.substr(0,n)) ans += c;
            return dp[n][m] = ans;
        }
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1]==b[m-1]) return dp[n][m] = rec(a,b,n-1,m-1,dp);
        int ans1 = 0, ans2 = 0;
        ans1 = a[n-1] + rec(a,b,n-1,m,dp); // del in string a
        ans2 = b[m-1] + rec(a,b,n,m-1,dp); // del in string b
        return dp[n][m] = min(ans1, ans2);
    } */
public:
    int minimumDeleteSum(string a, string b) {
        int n = a.size(), m = b.size();
        /* vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return rec(a,b,n,m,dp); */
        /* vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int curr = 0;
        for(int i=1; i<=n; i++) curr += a[i-1], dp[i][0] = curr;
        curr = 0;
        for(int j=1; j<=m; j++) curr += b[j-1], dp[0][j] = curr;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){ 
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                int ans1 = 0, ans2 = 0;
                ans1 = a[i-1] + dp[i-1][j];
                ans2 = b[j-1] + dp[i][j-1];
                dp[i][j] = min(ans1, ans2);
            }
        }
        return dp[n][m]; */
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j=1; j<=m; j++) prev[j] = prev[j-1] + b[j-1];
        for(int i=1; i<=n; i++){
            curr[0] = prev[0] + a[i-1];
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){ 
                    curr[j] = prev[j-1];
                }else{
                    int ans1 = a[i-1] + prev[j];
                    int ans2 = b[j-1] + curr[j-1];
                    curr[j] = min(ans1, ans2);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};