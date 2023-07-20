#define vi vector<int>
class Solution {
private:
    int n,m;
    int solve(int i,int j,int p,vector<vi> &dp,vi&v1,vi&v2){
        if(i==n) return 0;
        j = upper_bound(v2.begin()+j, v2.end(), p) - v2.begin();
        if(dp[i][j] != -1) return dp[i][j];
        if(j==m && v1[i]<=p) return 2001;
        int ans1 = 2001, ans2 = 2001;
        if(j!=m) ans1 = solve(i+1, j+1, v2[j], dp, v1, v2) + 1;
        if(v1[i]>p) ans2 = solve(i+1, j, v1[i], dp, v1, v2);
        return dp[i][j] = min(ans1, ans2);
    }
public:
    int makeArrayIncreasing(vector<int>&v1, vector<int>&v2) {
        n = v1.size(), m = v2.size();
        vector<vi> dp(2001,vi(2001,-1));
        sort(v2.begin(),v2.end());
        int a = solve(0,0,-1,dp,v1,v2);
        if(a>n) return -1;
        return a;
    }
};