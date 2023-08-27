// class Solution {
//     map<int, int> mp;
// private:
//     int rec(vector<int>&v, int i, int p, vector<vector<int>>&dp){
//         if(i==v.size()-1) return 1;
//         if(i>=v.size()) return 0;
//         if(dp[i][p] != -1) return dp[i][p];
//         int ans1, ans2, ans3; ans1 = ans2 = ans3 = false;
//         if(p==0){
//             if(mp[v[i]+1] == mp.end()) return 0;
//             return dp[i][p] = rec(v,i+1)
//         }
//     }
// public:
//     bool canCross(vector<int>& v) {
//         int n = v.size(); mp.clear();
//         for(int i=0; i<n; i++) mp[v[i]] = i;
//         vector<vector<int>> dp(n+1, vector<int>(INT_MAX, -1));
//         return rec(v,0,0,dp);
//     }
// };
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool f(vector<int>& v, int i, int k){
        if (i==n-1) return 1;
        if (i>=n) return 0;
        if (dp[i][k]!=-1) return dp[i][k];
        bool ans=0;
        for(int jump : {k-1, k, k+1}){
            if(jump==0) continue;
            int next = lower_bound(v.begin()+(i+1), v.end(), v[i]+jump) - v.begin();
            if (next==n || v[next]!=v[i]+jump) continue;
            ans = ans or f(v, next, jump);
        }
        return dp[i][k]=ans;
    }

    bool canCross(vector<int>& v) {
        n=v.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return f(v, 0, 0); 
    }
};