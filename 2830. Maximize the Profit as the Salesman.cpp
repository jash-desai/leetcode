#include<bits/stdc++.h>
class Solution {
private:
        int rec(vector<vector<int>>&v, int i, vector<int>&dp){
            if(i==v.size()) return 0;
            if(dp[i] != -1) return dp[i];
            int a = rec(v,i+1,dp);
            int l = i+1, r = v.size()-1, idx = v.size();
            while(l<=r){
                int m = (l + ((r-l) >> 1));
                if(v[m][0] > v[i][1]) r = m-1, idx = m;
                else l = m+1;
            }
            int b = v[i][2] + rec(v,idx,dp);
            return dp[i] = max(a,b);
        }
public:
    int maximizeTheProfit(int kk, vector<vector<int>>&v) {
        int n = v.size(); sort(v.begin(), v.end());
        // vector<int> dp(n+1, -1); return rec(v,0,dp);
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int a = dp[i+1], b = 0;
            int l = i+1, r = v.size()-1, idx = v.size();
            while(l<=r){
                int m = (l + ((r-l) >> 1));
                if(v[m][0] > v[i][1]) r = m-1, idx = m;
                else l = m+1;
            }
            b = v[i][2] + dp[idx];
            dp[i] = max(a,b);
        }
        return dp[0];
    }
};