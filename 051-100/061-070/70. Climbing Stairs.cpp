class Solution {
private:
    int rec(int n, vector<int>&dp){
        if(n==1 or n==2 or n==3) return n;
        if(dp[n] != 0) return dp[n]; 
        int ans1 = rec(n-1,dp);
        int ans2 = rec(n-2,dp);
        return dp[n] = (ans1+ans2);
    }
public:
    int climbStairs(int n) {
        if(n==1 or n==2 or n==3) return n;
        // vector<int> dp(n+1, 0);
        // return rec(n,dp);
        // for(int i=0; i<4; i++) dp[i]=i;
        // for(int i=4; i<=n; i++){
        //     int ans1 = dp[i-1];
        //     int ans2 = dp[i-2];
        //     dp[i] = ans1+ans2;
        // }
        // return dp[n];
        int curr=0, prev1=3, prev2=2;
        for(int i=4; i<=n; i++){
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};