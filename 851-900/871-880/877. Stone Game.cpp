class Solution {
private:
    int rec(vector<int>&v, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans1 = v[i] + min(rec(v,i+1,j,dp), rec(v,i+1, j-1, dp));
        int ans2 = v[j] + min(rec(v,i+1,j-1,dp), rec(v,i, j-2, dp));
        return dp[i][j] = max(ans1, ans2);
    }
public:
    bool stoneGame(vector<int>&v) {
        int n = v.size(), sum = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int &x : v) sum += x;
        int score = rec(v,0,n-1,dp);
        return (score>sum-score);
    }
};