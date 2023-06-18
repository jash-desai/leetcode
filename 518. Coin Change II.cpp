class Solution {
private:
    int rec(vector<int>&v, int n, int k, vector<vector<int>>&dp){
        if(k==0) return 1;
        if(n==0 or k<0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int ans1 = rec(v, n-1, k, dp);
        int ans2 = 0;
        if(k-v[n-1] >= 0) ans2 = rec(v, n, k-v[n-1], dp);
        return dp[n][k] = (ans1+ans2);
    }
public:
    int change(int k, vector<int>&v) {
        int n=v.size();
        if(k==0) return 1;
        if(n==1 and v[0]==k) return 1;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return rec(v,n,k,dp);
    }
};