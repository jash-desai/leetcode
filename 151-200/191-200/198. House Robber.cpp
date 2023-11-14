class Solution {
private:
    // int rec(vector<int>&v, int n, vector<int>&dp){
    //     if(n<=0) return 0;
    //     if(n==1) return v[0];
    //     if(dp[n] != -1) return dp[n];
    //     int ans1 = rec(v,n-1,dp);
    //     int ans2 = v[n-1] + rec(v,n-2,dp);
    //     return dp[n] = max(ans1, ans2);
    // }
public:
    int rob(vector<int>&v) {
        int n = v.size();
        /*
        vector<int> dp(n+1, -1);
        return rec(v,n,dp);
        dp[0]=0; dp[1]=v[0];
        for(int i=2; i<=n; i++){
            int ans1 = dp[i-1];
            int ans2 = v[i-1] + dp[i-2];
            dp[i] = max(ans1, ans2);
        }
        return dp[n];
        */
        int curr, prev1=v[0], prev2=0;
        for(int i=2; i<=n; i++){
            int ans1 = prev1;
            int ans2 = v[i-1] + prev2;
            if(ans1>ans2) curr=ans1;
            else curr=ans2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};