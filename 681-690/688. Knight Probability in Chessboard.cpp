#define vi vector<double>
#define vvi vector<vector<double>>
#define vvvi vector<vector<vector<double>>>
class Solution {
    vi dr = {-2, -2, -1, 1, 2, 2, -1, 1};
    vi dc = {-1, 1, 2, 2, -1, 1, -2, -2};
private:
    double rec(int&n, int k, int r, int c, vvvi&dp){
        if(r<0 or r>=n or c<0 or c>=n) return 0;
        if(k==0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double ans = 0;
        for(int i=0; i<8; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr<0 or nr>=n or nc<0 or nc>=n) continue;
            ans += rec(n,k-1,nr,nc,dp);
        }
        return dp[r][c][k] = ans;
    }
public:
    double knightProbability(int n, int k, int r, int c) {
        if(k==0) return 1.0;
        vvvi dp(n+1, vvi(n+1, vi(k+1, -1)));
        double cnt = rec(n,k,r,c,dp);
        double fav = pow(8, k);
        return ((double)cnt/(double)fav);
    }
};