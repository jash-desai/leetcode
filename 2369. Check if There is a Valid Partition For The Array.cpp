class Solution {
public:
    int n; vector<int> dp;
    bool rec(int i, vector<int>& v){
        if(i<0) return 1;
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        bool b0 = 0, b1 = 0, b2 = 0;
        if(i>0 and v[i]==v[i-1]) b0 = rec(i-2, v);
        if(i>1 and v[i]==v[i-1] and v[i-1]==v[i-2]) b1 = rec(i-3, v);
        if(i>1 and v[i]==v[i-1]+1 and v[i-1]==v[i-2]+1) b2 = rec(i-3, v);
        return dp[i] = (b0 or b1 or b2);
    }
    bool validPartition(vector<int>&v) {
        n = v.size(); dp.assign(n, -1);
        // return rec(n-1, v);
        dp.assign(n, 0);
        for(int i=1; i<n; i++){
            bool b0 = 0, b1 = 0, b2 = 0;
            if(i>0 and v[i]==v[i-1]){
                if(i-2<0) b0 = 1;
                else b0 = dp[i-2];
            }
            if(i>1 and v[i]==v[i-1] and v[i-1]==v[i-2]){
                if(i-3<0) b1 = 1;
                else b1 = dp[i-3];
            }
            if(i>1 and v[i]==v[i-1]+1 and v[i-1]==v[i-2]+1){ 
                if(i-3<0) b2 = 1;
                else b2 = dp[i-3];
            }
            dp[i] = (b0 or b1 or b2);
        }
        return dp[n-1];
    }
};