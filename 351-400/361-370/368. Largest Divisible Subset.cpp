class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>&v) {
        int n = v.size(); sort(v.begin(), v.end());
        vector<int> dp(n,1); vector<int> mp(n,0); 
        int idx = 0; int mx = 1;
        for(int i=1; i<n; i++){
            mp[i] = i;
            for(int j=0; j<i; j++){
                if(v[i]%v[j]==0 and dp[i]<(1+dp[j])){
                    dp[i] = 1 + dp[j];
                    mp[i] = j;
                    if(mx < dp[i]){
                        mx = dp[i]; idx = i;
                    }
                }
            }
        }
        vector<int> ans;
        while(mp[idx]!=idx){
            ans.push_back(v[idx]);
            idx = mp[idx];
        }
        ans.push_back(v[idx]);
        return ans;
    }
};