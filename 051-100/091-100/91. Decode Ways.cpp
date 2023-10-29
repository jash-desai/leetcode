class Solution {
private:
    int rec(string s, int i, vector<int>&dp){
        if(i==s.size()) return 1;
        if(i==s.size()-1) return (s[i]!='0');
        if(dp[i] != -1) return dp[i];
        int one = stoi(s.substr(i,1));
        if(!one) return dp[i] = 0;
        int a = rec(s,i+1,dp), b = 0;
        int two = stoi(s.substr(i,2));
        if(two<=26) b = rec(s,i+2,dp);
        return dp[i] = a + b;
    }
public:
    int numDecodings(string s) {
        int n = s.size(); 
        // vector<int> dp(101, -1); return rec(s,0,dp);
        /* vector<int> dp(101, 0);
        dp[n] = 1; dp[n-1] = (s[n-1] != '0');
        for(int i=n-2; i>=0; i--){
            int one = stoi(s.substr(i, 1));
            if(!one) continue; // if one is 0 : there can't be a valid two.
            dp[i] += dp[i+1]; // count individual one.
            int two = stoi(s.substr(i, 2));
            if(two <= 26) dp[i] += dp[i+2];
        } return dp[0]; */
        int prev2 = 1, prev1 = (s[n-1]!='0'), curr = 0;
        for(int i=n-2; i>=0; i--){
            int one = stoi(s.substr(i,1));
            if(!one){
                prev2 = prev1;
                prev1 = curr;
                curr = 0;
                continue;
            }
            curr += prev1;
            int two = stoi(s.substr(i,2));
            if(two<=26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
            curr = 0;
        }   
        return prev1;
    }
};