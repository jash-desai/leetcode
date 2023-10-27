class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); string ans; int mx = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int d=0; d<n; d++){
            for(int i=0, j=i+d; j<n; i++, j++){
                if(i==j) dp[i][j] = 1;
                else if(d==1 and s[i]==s[j]) dp[i][j] = 2;
                else{
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1] > 0){
                            dp[i][j] = dp[i+1][j-1] + 2;
                        }
                    }
                }
                if(dp[i][j] > 0){
                    if(j-i+1 > mx){
                        mx = j-i+1;
                        ans = s.substr(i, mx);
                    }
                }
            }
        }
        return ans;
    }
};

/* : why is this not working.
class Solution {
public:
    string longestPalindrome(string a) {
        string b = a; reverse(begin(b), end(b)); int n = a.size();
        int m = n; vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i{1}; i<n+1; i++){
            for(int j{1}; j<m+1; j++){
                if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
            }
        }
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
        string ans=""; int r=n, c=m;
        while(r>0 and c>0){
            if(a[r-1] == b[c-1]){
                ans.push_back(a[r-1]);
                r--, c--;
            }else{
                if(dp[r-1][c] > dp[r][c-1]) r--;
                else c--;
            }
        }
        return ans;
    }
};
*/

