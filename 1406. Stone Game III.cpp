class Solution {
public:
    int solve(int i, int n, vector<int> &s, int dp[]){
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];
        int tot = 0, ans = INT_MIN;
        for(int j = 0; j < 3; j++){
            if(i+j<s.size()) tot+=s[i+j];
            ans = max(ans, tot - solve(i+j+1, n, s, dp));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(); int dp[n];
        memset(dp, -1, sizeof(dp));
        int tp = solve(0, n, stoneValue, dp);
        if(tp > 0) return "Alice";
        else if(tp < 0) return "Bob";
        else return "Tie";
    }
};