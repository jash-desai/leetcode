#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
    int n, k;
public:
    int longestSubsequence(vector<int>&v, int k){
        // O(N^2) gives TLE.
        // n = size(v); k = K; 
        /* vvi dp(n+1, vi(n+2, -1));
        return rec(v,0,-1,dp); */
        /*
        vvi dp(n+1, vi(n+2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=-1; j--){
                if(j==-1){
                    int ans1 = dp[i+1][j+1];
                    int ans2 = 1 + dp[i+1][i+1];
                    dp[i][j+1] = max(ans1,ans2);
                }else{
                    int ans1 = dp[i+1][j+1];
                    int ans2 = 0;
                    if(v[i]-v[j] == k) ans2 = 1 + dp[i+1][i+1];
                    dp[i][j+1] = max(ans1,ans2);
                }
            }
        }
        return dp[0][0];
        */
        /*
        vi dp(n,1); int ans = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(v[i]-v[j] == k){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        */
        unordered_map<int, int> mp; int mx = 0;
        for(int i : v){
            mp[i] = mp[i-k] + 1;
            mx = max(mp[i], mx);
        }
        return mx;
    }
};
