using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
class Solution {
    map<int, pair<int,int>> mp;
private:
    int rec(vector<string>&v, int i, int n, int m, vvvi&dp){
        if(i==v.size()) return 0;
        if(n<0 or m<0) return 0;
        if(dp[i][n][m] != -1) return dp[i][n][m];
        int a = rec(v,i+1,n,m,dp), b = 0;
        if(n>=mp[i].first and m>=mp[i].second) b = 1 + rec(v,i+1,n-mp[i].first, m-mp[i].second,dp);
        return dp[i][n][m] = max(a,b);
    }
public:
    int findMaxForm(vector<string>&v, int n, int m) {
        mp.clear();
        for(int i=0; i<v.size(); i++){
            int z = count(begin(v[i]), end(v[i]), '0');
            mp[i] = {z, size(v[i])-z};
        }
        /* vvvi dp(size(v)+1, vvi(n+1, vi(m+1, -1)));
        return rec(v,0,n,m,dp); */
        /*
        vvvi dp(size(v)+1, vvi(n+1, vi(m+1, 0)));
        for(int i=v.size()-1; i>=0; i--){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=m; k++){
                    int a = dp[i+1][j][k], b = 0;
                    if(j>=mp[i].first and k>=mp[i].second){
                        b = 1 + dp[i+1][j-mp[i].first][k-mp[i].second];
                    }
                    dp[i][j][k] = max(a,b);
                }
            }
        }
        return dp[0][n][m];
        */
        vvi prev(n+1, vi(m+1, 0)), curr(n+1, vi(m+1, 0));
        for(int i=v.size()-1; i>=0; i--){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=m; k++){
                    int a = prev[j][k], b = 0;
                    if(j>=mp[i].first and k>=mp[i].second){
                        b = 1 + prev[j-mp[i].first][k-mp[i].second];
                    }
                    curr[j][k] = max(a,b);
                }
            }
            prev = curr;
        }
        return prev[n][m];
    }
};