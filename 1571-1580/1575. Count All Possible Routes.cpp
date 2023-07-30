class Solution {
private:
    int n; int mod = 1e9+7;
    int rec(vector<int>&v, int s, int e, int f, vector<vector<int>>&dp){
        if(f<0) return 0;
        if(dp[s][f] != -1) return dp[s][f];
        int ans = 0;
        if(s==e) ans++;
        for(int i=0; i<n; i++){
            if(i==s) continue;
            int temp = rec(v,i,e,f-abs(v[i]-v[s]),dp);
            ans = (ans+temp)%mod;
        }
        return dp[s][f] = (ans)%mod;
    }
public:
    int countRoutes(vector<int>&v, int s, int e, int f){
        n = v.size(); vector<vector<int>> dp(n+1, vector<int>(f+1, -1));
        return rec(v,s,e,f,dp);
    }
};