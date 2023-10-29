#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
private:
    // not working as of now.
    /* int rec(string&a, string&b, string&c, int n, int m, int o, vvi&dp){
        if(o==0 and n==0 and m==0) return 1;
        if(n==0 and b[m-1] != c[o-1]) return 0;
        if(m==0 and a[n-1] != c[o-1]) return 0;
        if(a[n-1] != c[o-1] and b[m-1] != c[o-1]) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        if(a[n-1] == c[o-1] and b[m-1] != c[o-1]){
            return dp[n][m] = rec(a,b,c,n-1,m,o-1,dp);
        }else if(b[m-1] == c[o-1] and a[n-1] != c[o-1]){ 
            return dp[n][m] = rec(a,b,c,n,m-1,o-1,dp);
        }
        int ans1 = rec(a,b,c,n-1,m,o-1,dp);
        int ans2 = rec(a,b,c,n,m-1,o-1,dp);
        return dp[n][m] = (ans1==1 or ans2==1);
    } */
    int rec(string&a, string&b, string&c, int i, int j, int k, vvi&dp){
        if(k==c.size() and i==a.size() and j==b.size()) return 1;
        if(i==a.size() and b[j] != c[k]) return 0;
        if(j==b.size() and a[i] != c[k]) return 0;
        if(a[i] != c[k] and b[j] != c[k]) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == c[k] and b[j] != c[k]){
            return dp[i][j] = rec(a,b,c,i+1,j,k+1,dp);
        }else if(b[j] == c[k] and a[i] != c[k]){ 
            return dp[i][j] = rec(a,b,c,i,j+1,k+1,dp);
        }
        int ans1 = rec(a,b,c,i+1,j,k+1,dp);
        int ans2 = rec(a,b,c,i,j+1,k+1,dp);
        return dp[i][j] = (ans1==1 or ans2==1);
    }
public:
    bool isInterleave(string a, string b, string c) {
        int n = a.size(), m = b.size(), o = c.size();
        if(n+m != o) return false;
        vvi dp(n+1, vi(m+1, -1)); 
        // return rec(a,b,c,n,m,o,dp);
        return rec(a,b,c,0,0,0,dp);
    }
};