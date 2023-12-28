class Solution {
public:
    int findNumberOfLIS(vector<int>&v) {
        int n = v.size(); int lis = 1;
        vector<int> dp(n,1), cnt(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(v[i]>v[j]){
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1+dp[j];
                        cnt[i] = cnt[j];
                    }else if(dp[i]==1+dp[j]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            lis = max(lis, dp[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i]==lis) ans += cnt[i];
        }
        return ans;
    }
};