class Solution {
// private:
//     int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
//         if(n==0 and m==0) return 1;
//         if(n>0 and m<=0) return 0;
//         if(n<=0 and m>0){
//             for(char x : b.substr(0,m)) if(x != '*') return 0;
//             return 1;
//         } 
//         if(dp[n][m] != -1) return dp[n][m];
//         if(a[n-1]==b[m-1] or b[m-1]=='?'){
//             return dp[n][m] = rec(a,b,n-1,m-1,dp);
//         }else if(b[m-1]=='*'){
//             int ans1, ans2, ans3;
//             ans1 = rec(a,b,n,m-1,dp); // 0
//             ans2 = rec(a,b,n-1,m,dp); // 1+
//             return dp[n][m] = (ans1==1 or ans2==1) ? 1 : 0;
//         } 
//         return dp[n][m] =  0;
//     }
public:
    bool isMatch(string a, string b) {
        int n = a.size(), m = b.size();
        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return rec(a,b,n,m,dp);
        dp[0][0] = 1;
        for(int j=1; j<=m; j++){
            dp[0][j] = ((b[j-1]=='*') and (dp[0][j-1]==1)) ? 1 : 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1] or b[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(b[j-1]=='*'){
                    int ans1 = dp[i][j-1];
                    int ans2 = dp[i-1][j];
                    dp[i][j] = (ans1==1 or ans2==1) ? 1 : 0;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
        */
        vector<int> prev(m+1, 0), curr(m+1, 0);
        prev[0]=1;
        for(int j=1; j<=m; j++){
            prev[j] = ((b[j-1]=='*') and (prev[j-1]==1)) ? 1 : 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1] or b[j-1]=='?'){
                    curr[j] = prev[j-1];
                }else if(b[j-1]=='*'){
                    int ans1 = curr[j-1];
                    int ans2 = prev[j];
                    curr[j] = (ans1==1 or ans2==1) ? 1 : 0;
                }else curr[j]=0;
            }
            prev = curr;
        }
        return prev[m];
    }
};