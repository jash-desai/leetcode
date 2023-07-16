class Solution {
private:
    int rec(vector<int>&v, int i, vector<int>&dp){
        if(i<0 or i>=size(v) or v[i]<0) return 0;
        if(dp[i] != -1) return dp[i];
        if(v[i]==0) return dp[i] = 1;
        v[i] = -v[i];
        int ans1 = rec(v,i-v[i],dp);
        int ans2 = rec(v,i+v[i],dp);
        return dp[i] = (ans1==1 or ans2==1);
    }
public:
    bool canReach(vector<int>&v, int s){
        if(v[s]==0) return 1;
        vector<int> dp(size(v), -1);
        return rec(v,s,dp);
    }
};