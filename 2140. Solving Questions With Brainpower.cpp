#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
class Solution {
private:
    ll rec(vector<vector<int>>&v, int i, vi&dp){
        if(i>=v.size()) return 0;
        if(dp[i] != -1) return dp[i];
        ll a = rec(v,i+1,dp);
        ll b = v[i][0] + rec(v,i+v[i][1]+1,dp);
        return dp[i] = max(a,b); 
    }
public:
    long long mostPoints(vector<vector<int>>&v) {
        int n = v.size(); 
        // vi dp(n+1, -1); return rec(v,0,dp);
        vi dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            ll a = dp[i+1], b = 0;
            int ni = min(i+v[i][1]+1, n);
            b = v[i][0] + dp[ni];
            dp[i] = max(a,b);
        } return dp[0]; 
    }
};