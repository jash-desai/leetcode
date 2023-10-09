class Solution {
    int dp[505][505];
private:
    int rec(vector<int>&a, vector<int>&b, int n, int m){
        if(n==0 or m==0) return 0;
        if(dp[n][m] != 0) return dp[n][m];
        int ans1 = max({rec(a,b,n-1,m), rec(a,b,n,m-1), rec(a,b,n-1,m-1)});
        int ans2 = (a[n-1]*b[m-1]) + rec(a,b,n-1,m-1);
        return dp[n][m] = max(ans1, ans2);
    }
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int mina = *min_element(begin(a), end(a));
        int maxa = *max_element(begin(a), end(a));
        int minb = *min_element(begin(b), end(b));
        int maxb = *max_element(begin(b), end(b));
        if(maxa<0 and minb>0) return maxa*minb;
        if(mina>0 and maxb<0) return mina*maxb;
        memset(dp, 0, sizeof(dp));
        return rec(a,b,n,m);
    }
};