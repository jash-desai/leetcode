class Solution {
    vector<vector<int>>dp;
private:
    int rec(vector<vector<int>>&v, int idx, int k, int end){
        if(idx==size(v) or k==0) return 0;
        if(v[idx][0] <= end) return rec(v, idx+1, k, end);
        if(dp[idx][k] != -1) return dp[idx][k];
        int ans1 = v[idx][2] + rec(v, idx+1, k-1, v[idx][1]);
        int ans2 = rec(v, idx+1, k, end);
        return dp[idx][k] = max(ans1, ans2);
    }
public:
    int maxValue(vector<vector<int>>& v, int k) {
        sort(begin(v), end(v)); int n = size(v);
        dp.resize(n, vector<int>(k+1, -1));
        return rec(v,0,k,0);
    }
};