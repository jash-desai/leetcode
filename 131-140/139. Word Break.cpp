class Solution {
private:
    int rec(string&s, int i, unordered_set<string>&st, vector<int>&dp){
        if(i==s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        for(int j=i; j<s.size(); j++){
            string t = s.substr(i, j-i+1);
            if(st.count(t) and rec(s,j+1,st,dp)){
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>&v) {
        unordered_set<string> st(v.begin(), v.end());
        if(st.find(s) != st.end()) return 1;
        // vector<int> dp(size(s)+1, -1); return rec(s,0,st,dp);
        int n = s.size(); vector<int> dp(n+1, 0); dp[n]=1;
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                string t = s.substr(i, j-i+1);
                if(st.count(t) and dp[j+1]){
                    dp[i] = dp[j+1];
                }
            }
        }

        return dp[0];
    }
};