class Solution {
private:
    int rec(vector<int>&v, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return v[i];
        if(i+1==j) return max(v[i], v[j]);
        if(dp[i][j] != -1) return dp[i][j];
        int ans1 = v[i] + min(rec(v,i+2,j,dp), rec(v,i+1,j-1,dp));
        int ans2 = v[j] + min(rec(v,i+1,j-1,dp), rec(v,i,j-2,dp));
        return dp[i][j] = max(ans1, ans2);
    }
public:
    bool PredictTheWinner(vector<int>&v) {
        int n = size(v), sum = 0;
        for(int &x : v) sum += x;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int score = rec(v,0,n-1,dp);
        return (score >= (sum-score));
    }
};