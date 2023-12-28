class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,0));
        int count=0;
        for(int d=0; d<n; d++){
            for(int i=0,j=d; j<n; i++,j++){
                if(d==0){
                    dp[i][j]=1;
                }else if(d==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                }else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j]) count++;
            }
        }
        return count;
        
    }
};