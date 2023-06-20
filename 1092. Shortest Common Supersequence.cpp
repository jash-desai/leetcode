class Solution {
private:
    vector<vector<int>> rec(string&a, string&b, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp;
    }
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp = rec(a,b,n,m);
        int lcs = dp[n][m];
        int i=n, j=m; string ans;
        int idx = n+m-lcs-1;
        while(i>=1 and j>=1){
            if(a[i-1] == b[j-1]){
                ans.push_back(a[i-1]);
                i--, j--;
            }else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans.push_back(b[j-1]);
                    j--;
                }else{
                    ans.push_back(a[i-1]);
                    i--;
                }
            }
        }
        if(i!=0){ 
            while(i>0){
                ans.push_back(a[i-1]);
                i--;
            }
        }
        if(j!=0){
            while(j>0){
                ans.push_back(b[j-1]);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};