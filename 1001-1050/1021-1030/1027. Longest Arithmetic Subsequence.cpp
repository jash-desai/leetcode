class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {
        int ans  = 0; int n = v.size();
        if(n<3) return n;
        unordered_map<int,int> dp[n]; // array of map.
        for(int i=1; i<n; i++){
            for(int j = 0; j<i; j++){
                int d = v[i]-v[j], cnt = 1;
                if(dp[j].count(d)){
                    cnt += 1 + (dp[j][d] - 1);
                    dp[i][d] = cnt;
                }
                else dp[i][d] = 1 + cnt;
                ans  = max(ans, dp[i][d]);
            }
        } return ans;
    }
};