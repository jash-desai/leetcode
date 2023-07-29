class Solution {
private:
    int rec(vector<int>&v, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i; k<=j; k++){
            int curr = v[i-1]*v[k]*v[j+1];
            curr += (rec(v,i,k-1,dp) + rec(v,k+1,j,dp));
            ans = max(curr, ans);
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>&v) {
        int n = size(v); v.push_back(1); v.insert(v.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return rec(v,1,n,dp);
    }
};