class Solution {
public:
    int stoneGameII(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        vector<int> sufsum (n+1, 0);
        for(int i=n-1; i>=0; i--) sufsum[i] = sufsum[i+1] + v[i]; 
        return rec(dp, sufsum, 0, 1);
    }
    int rec(vector<vector<int>>&dp, vector<int>&sufsum, int i, int m) {
        if(i == sufsum.size()) return 0;
        if((2*m) >= sufsum.size()-i) return sufsum[i];
        if(dp[i][m] != 0) return dp[i][m];
        int res = INT_MAX;
        for(int x=1; x<=(2*m); x++){
            res = min(res, rec(dp, sufsum, i+x, max(x,m)));
        }
        dp[i][m] = sufsum[i] - res;
        return dp[i][m];
    }
};