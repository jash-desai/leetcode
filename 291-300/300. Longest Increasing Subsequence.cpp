#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>
#define vi vector<int>

class Solution {
    int n;
private:
    // int rec(vector<int>&v, int i, int k, vvi&dp){
    //     if(i==n) return 0;
    //     if(dp[i][k+1] != -1) return dp[i][k+1];
    //     int ans = rec(v,i+1,k,dp);
    //     if(k==-1 or v[i]>v[k]){
    //         ans = max(ans, 1 + rec(v,i+1,i,dp));
    //     }
    //     return dp[i][k+1] = ans;
    // }
public:
    int lengthOfLIS(vector<int>&v){
        n = v.size(); 
        /*
        vvi dp(n+1, vi(n+1, 0));
        // return rec(v,0,-1,dp);
        for(int i=n-1; i>=0; i--){
            for(int k=i; k>=-1; k--){
                int ans = dp[i+1][k+1];
                if(k==-1 or v[i]>v[k]){
                    ans = max(ans, 1 + dp[i+1][i+1]);
                }
                dp[i][k+1] = ans;
            }
        }
        return dp[0][0];
        */
        /*
        vi prev(n+1, 0), curr(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int k=i; k>=-1; k--){
                int ans = prev[k+1];
                if(k==-1 or v[i]>v[k]){
                    ans = max(ans, 1 + prev[i+1]);
                }
                curr[k+1] = ans;
            }
            prev = curr;
        }
        return prev[0];
        */
        /*
        vi dp(n,1); int ans = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(v[i]>v[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        */
        vi ans = {v[0]};
        for(int i=1; i<n; i++){
            auto it = lower_bound(all(ans), v[i]);
            if(it == ans.end()) ans.push_back(v[i]);
            else *it = v[i];
        }
        return ans.size();
    }
};