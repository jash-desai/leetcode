class Solution {
private:
    bool rec(vector<int>&v, int k, int n, vector<vector<int>>&dp){
        if(k==0) return 1;
        if(n==0 or k<0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        bool ans1 = rec(v, k-v[n-1], n-1, dp);
        bool ans2 = rec(v, k, n-1, dp);
        return dp[n][k] = (ans1 or ans2);
    }
public:
    bool canPartition(vector<int>&v) {
        int s = 0, n = v.size();
        for(int x : v) s += x;
        if(s%2 or n==1) return false;
        int k = s>>1; 
        /* 2D DP declaration :
        vector<vector<int>> dp;
        dp.resize(n+1, vector<int>(k+1, -1));
        /* Memoization 2D DP Solution : 
        return rec(v, k, n);
        /* Tabulation 2D DP Solution :
        for(int j=0; j<=k; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(j >= v[i-1]){
                    int ans1 = dp[i-1][j - v[i-1]];
                    int ans2 = dp[i-1][j]; 
                    dp[i][j] = (ans1==1 or ans2==1)  ? 1 : 0;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][k];
        */
        /* 1D DP Tabulation Solution : 
        */
        vector<int> prev(k+1, -1); vector<int> curr(k+1, -1);
        prev[0] = 1; curr[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if(j >= v[i-1]){
                    int ans1 = prev[j - v[i-1]];
                    int ans2 = prev[j]; 
                    curr[j] = (ans1==1 or ans2==1)  ? 1 : 0;
                }else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
            fill(curr.begin()+1, curr.end(), -1);
            curr[0]=1;
        }
        return prev[k];
    }
};