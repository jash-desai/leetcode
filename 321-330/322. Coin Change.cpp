#define vi vector<int>
class Solution {
private:
    // vector<vi> dp;
    vi dp2;
    // 2d DP matrix - not needed.
    // int rec(vi&v, int k, int n ){
    //     if(k==0) return 0;
    //     if(n==0 or k<0) return INT_MAX;
    //     if(dp[n][k] != -2) return dp[n][k];
    //     // skipping nth coin - not including
    //     int a = rec(v,k,n-1);
    //     // taking nth coin - target k updated : n same
    //     int t = rec(v, k-v[n-1], n);
    //     int b;
    //     if(t==INT_MAX) b=INT_MAX;
    //     else b = 1+t;
    //     return dp[n][k] = min(a,b);
    // }
public:
    int coinChange(vector<int>&v, int k) {
        if(k==0) return k;
        int n=v.size();
        if(n==0) return -1;
        // iterative 2d dp : 
        // dp.resize(n+1, vi(k+1,INT_MAX));
        // for(int i=0; i<k+1; i++) dp[0][i]=-1;
        // for(int i=0; i<n+1; i++) dp[i][0]=0;
        // return rec(v,k,n) == INT_MAX ? -1 : dp[n][k];
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
        dp2.resize(k+1,INT_MAX);
        dp2[0]=0;
        // iterative 1d dp : 
        for(int i=1; i<k+1; i++){
            for(int j=0; j<n; j++){
                if(v[j] <= i){
                    int t = dp2[i-v[j]];
                    if(t!=INT_MAX) dp2[i] = min(dp2[i], 1+t);
                }
            }
        }
        return dp2[k] == INT_MAX ? -1 : dp2[k];
    }
};