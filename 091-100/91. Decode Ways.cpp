class Solution {
public:
    int fun(char a,char b){
        int res=(a-'0')*10+b-'0';
        return res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        dp[0]=(s[0]=='0')?0:1;
        if(n==1) return dp[0];
        if(s[1]!='0'){
            dp[1]=dp[0];
            dp[1]=dp[1]+((1<=fun(s[0],s[1]) && fun(s[0],s[1])<=26 && s[0]!='0')?1:0);
        }else{
            if((1<=fun(s[0],s[1]) && fun(s[0],s[1])<=26)) dp[1]=dp[0];
        }
        for(int i=2;i<n;i++){
            if(s[i]!='0') dp[i]=dp[i-1];
            if((1<=fun(s[i-1],s[i]) && fun(s[i-1],s[i])<=26 && s[i-1]!='0')) dp[i]+=dp[i-2];
        }
        return dp[n-1];
    }
};