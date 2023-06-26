class Solution {
private:
    int mod = 1e9+7;
    // int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
    //     if(n<=0 and m>0) return 0;
    //     if(m==0) return 1;
    //     if(dp[n][m] != -1) return dp[n][m];
    //     int ans1 = 0, ans2 = 0, ans3 = 0;
    //     if(a[n-1]==b[m-1]){
    //         ans1 = rec(a,b,n-1,m-1,dp);
    //         ans2 = rec(a,b,n-1,m,dp);
    //     }else{
    //         ans3 = rec(a,b,n-1,m,dp);
    //     }
    //     return dp[n][m] = (ans1+ans2+ans3)%mod;
    // }
public:
    int numDistinct(string a, string b) {
        int n = a.size(), m = b.size();
        /*
        vector<vector<long long int>> dp(n+1, vector<long long int>(m+1, 0));
        // return rec(a,b,n,m,dp);
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                long long int ans1 = 0, ans2 = 0, ans3 = 0;
                if(a[i-1]==b[j-1]){
                    ans1 = dp[i-1][j-1];
                    ans2 = dp[i-1][j];
                }else{
                    ans3 = dp[i-1][j];
                }
                dp[i][j] = (ans1+ans2+ans3)%mod;
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1, 0), curr(m+1, 0); 
        prev[0]=1; curr[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                long long int ans1 = 0, ans2 = 0, ans3 = 0;
                if(a[i-1]==b[j-1]){
                    ans1 = prev[j-1];
                    ans2 = prev[j];
                }else{
                    ans3 = prev[j];
                }
                curr[j] = (ans1+ans2+ans3)%mod;
            }
            prev = curr; curr[0]=1;
        }
        return prev[m];
    }
};