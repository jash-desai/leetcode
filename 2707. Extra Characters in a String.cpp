class Solution {
public:
    int minExtraChar(string s, vector<string>& v) {
        int n = s.size(); vector<int> dp(n+1, n+1);
        dp[0] = 0; unordered_set<string> st(v.begin(), v.end());
        for(int i{1}; i<=n; i++){
            dp[i] = 1 + dp[i-1]; // case 1 : extra character considered.
            for(int l = 1; l <= i; l++){
                string t = s.substr(i-l, l);
                if(st.count(t)) dp[i] = min(dp[i], dp[i-l]);
            }
        }
        return dp[n];
    }
};