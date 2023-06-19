class Solution {
private:
    int lcs(string&a, string&b, int n, int m){
        if(n==0 or m==0) return 0;
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> curr(m+1,0), prev(m+1,0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
public:
    int minInsertions(string a) {
        int n = a.size(); string b(a.rbegin(), a.rend());
        // reverse(b.begin(), b.end());
        return n - lcs(a,b,n,n);
    }
};