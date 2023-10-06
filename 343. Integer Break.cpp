class Solution {
public:
    int integerBreak(int n) {
        if(n==2 or n==3) return n-1;
        int ans = 1;
        while(n>4){
            ans *= 3; n -= 3;
        }
        ans *= n;
        return ans;
    }
};
/*
class Solution {
    int ans = 1;
private:
    int rec(int n, vector<int>&dp){
        if(n==1 or n==2) return 1;
        if(dp[n] != -1) return dp[n];
        int curr = 1;
        for(int i=1; i<n; i++){
            curr = max(curr, (max(i, rec(i,dp))*max(n-i, rec(n-i,dp))));
            ans = max(ans, curr);
        }
        return dp[n] = curr;
    }
public:
    int integerBreak(int n) {
        if(n==1 or n==2) return 1;
        vector<int> dp(n+5, -1);
        ans = 1; rec(n, dp); return ans;
    }
};
*/