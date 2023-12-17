class Solution {
private:
    int rec(vector<int>&v, int k, vector<int>&dp){
        if(!k) return 1;
        if(dp[k] != -1) return dp[k];
        int a = 0;
        for(int i=0; i<v.size(); i++){
            if(k-v[i] >= 0) a += rec(v,k-v[i],dp);
        }
        return dp[k] = a;
    }
public:
    int combinationSum4(vector<int>&v, int k) {
        // vector<int> dp(k+1, -1); return rec(v,k,dp);
        vector<int> dp(k+1, 0); dp[0] = 1;
        for(int i=1; i<=k; i++){
            long long int a = 0;
            for(int j=0; j<v.size(); j++){
                if(i-v[j] >= 0) a += dp[i-v[j]];
            } dp[i] = a;
        }
        return dp[k];
    }
};