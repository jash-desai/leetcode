class Solution {
    int dp[55][105][55], n, m;
    const int mod = 1e9+7;
private:
    int rec(int i, int mx, int k){
        if(i==n and k==0) return 1;
        if(i==n or k<0 or mx>m) return 0;
        if(dp[i][mx][k] != -1) return dp[i][mx][k];
        long long int ans1 = (mx*1LL*rec(i+1,mx,k))%mod;
        long long int ans2 = 0;
        for(int nmx=mx+1; nmx<=m; nmx++){
            ans2 = (ans2 + rec(i+1,nmx,k-1))%mod;
        }
        return dp[i][mx][k] = (ans1 + ans2)%mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        if(m<k) return 0;
        this->n = n; this->m = m;
        memset(dp, -1, sizeof dp);
        return rec(0,0,k);
    }
};