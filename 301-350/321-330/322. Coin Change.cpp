#define vi vector<int>
class Solution {
private:
    // vector<vi> dp;
    vi dp2;
    // int rec(vi&v, int k, int n ){
    //     if(k==0) return 0;
    //     if(n==0 or k<0) return INT_MAX;
    //     if(dp[n][k] != -1) return dp[n][k];
    //     int a = rec(v,k,n-1);
    //     int b = INT_MAX;
    //     if(k-v[n-1] >= 0) b = 1 + rec(v, k-v[n-1], n);
    //     return dp[n][k] = min(a,b);
    // }
public:
    int coinChange(vector<int>&v, int k) {
        if(k==0) return k;
        int n=v.size();
        if(n==0) return -1;
        // dp.resize(n+1, vi(k+1,INT_MAX));
        // return rec(v,k,n) == INT_MAX ? -1 : dp[n][k];
        // for(int i=0; i<k+1; i++) dp[0][i]=-1;
        // for(int i=0; i<n+1; i++) dp[i][0]=0;
        // for(int i=1; i<n+1; i++){
        //     for(int j=1; j<k+1; j++){
        //         int a = dp[i-1][j];
        //         int b = INT_MAX;
        //         if(j>=v[i-1]){
        //             b = 1+dp[i][j-v[i-1]];
        //         }
        //         dp[i][j] = min(a,b);
        //     }
        // }
        // return dp[n][k]==INT_MAX ? -1 : dp[n][k];
        vector<int> curr(k+1, INT_MAX), prev(k+1,INT_MAX);
        prev[0]=0; curr[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                int ans1 = prev[j];
                int ans2 = INT_MAX;
                if(j-v[i-1] >= 0) ans2 = curr[j-v[i-1]];
                if(ans2 != INT_MAX) ans2++;
                curr[j] = min(ans1, ans2);
            }
            prev = curr;
            fill(begin(curr), end(curr), 0);
        }
        return prev[k]==INT_MAX ? -1 : prev[k];
    }
};