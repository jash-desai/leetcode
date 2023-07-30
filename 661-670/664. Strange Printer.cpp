class Solution {
public:
    int dp[101][101];
    int rec(int i, int j, string &s){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        ans = min(ans, 1 + rec(i+1,j,s));
        for(int k=i+1; k<=j; k++){
            if(s[i]==s[k]){
                ans = min(ans, rec(i+1,k-1,s) + rec(k,j,s));
            }
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        memset(dp, -1, sizeof dp);
        string str;
        for(int i=0; i<s.size();){
            char ch = s[i];
            while(i<s.size() and ch==s[i]) i++;
            str.push_back(ch);
        }     
        return rec(0, str.size()-1, str);
    }
};