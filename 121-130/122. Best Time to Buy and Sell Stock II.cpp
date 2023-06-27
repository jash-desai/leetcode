class Solution{
private:
    int n;
    // int rec(vector<int>&v, int i, int flag, vector<vector<int>>&dp){
    //     if(i>=n) return 0;
    //     if(dp[i][flag] != -1) return dp[i][flag];
    //     int ans1,ans2;
    //     if(flag){
    //         ans1 = -v[i] + rec(v,i+1,0,dp);
    //         ans2 = rec(v,i+1,1,dp);
    //     }else{
    //         ans1 = v[i] + rec(v,i+1,1,dp);
    //         ans2 = rec(v,i+1,0,dp);
    //     }
    //     return dp[i][flag] = max(ans1,ans2);
    // }
public:
    int maxProfit(vector<int>&v) {
        n = v.size(); 
        /* 
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return rec(v,0,true,dp);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int ans = 0;
                if(j==1){
                    ans = max(-v[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    ans = max(v[i] + dp[i+1][1], dp[i+1][0]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][1];
        */
        /*
        vector<int> prev(2,0), curr(2,0);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int ans;
                if(j){
                    ans = max(-v[i] + prev[0], prev[1]);
                }else{
                    ans = max(v[i] + prev[1], prev[0]);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[1];
        */
        int prevBuy = 0, prevSell = 0;
        int currBuy = 0, currSell = 0;
        for(int i=n-1; i>=0; i--){
            // not buy
            currSell = max(v[i]+prevBuy, prevSell);
            // buy
            currBuy = max(-v[i]+prevSell, prevBuy);
            prevBuy = currBuy; prevSell = currSell;
        }
        return prevBuy;
    }
};