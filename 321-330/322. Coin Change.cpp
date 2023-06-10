#define vi vector<int>
class Solution {
private:
    int rec(vi&v, int k, int n, vector<vi>&dp){
        if(k==0) return 0;
        if(n==0 or k<0) return INT_MAX;
        if(dp[n][k] != -2) return dp[n][k];
        // skipping nth coin - not including
        int a = rec(v,k,n-1,dp);
        // taking nth coin - target k updated : n same
        int t = rec(v, k-v[n-1], n, dp);
        int b;
        if(t==INT_MAX) b=INT_MAX;
        else b = 1+t;
        return dp[n][k] = min(a,b);
    }
public:
    int coinChange(vector<int>&v, int k) {
        if(k==0) return k;
        int n=v.size();
        if(n==0) return -1;
        vector<vi> dp(n+1, vi(k+1,-2));
        for(int i=0; i<k+1; i++) dp[0][i]=-1;
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        return rec(v,k,n,dp) == INT_MAX ? -1 : dp[n][k];
    }
};