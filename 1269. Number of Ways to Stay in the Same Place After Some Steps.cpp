class Solution {
    unordered_map<string, long long int> mp;
    vector<vector<int>> dp;
    int n; const int mod = 1e9+7;
private:
    /*
    int rec(int i, int k){
        if(i==0 and k==0) return 1;
        if(k==0) return 0;
        if(i<0 or i>=n) return 0;
        string key = to_string(i) + "::" + to_string(k);
        if(mp.count(key)) return mp[key];
        int ans1 = rec(i, k-1);
        int ans2 = rec(i-1, k-1);
        int ans3 = rec(i+1, k-1);

        return mp[key] = ((ans1+ans2)%mod+ans3)%mod;
    }
    */
    int rec(int i, int k){
        if(i==0 and k==0) return 1;
        if(k==0) return 0;
        if(i<0 or i>=n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int ans1 = rec(i, k-1);
        int ans2 = rec(i-1, k-1);
        int ans3 = rec(i+1, k-1);
        return dp[i][k] = ((ans1+ans2)%mod+ans3)%mod;
    }
public:
    int numWays(int k, int n) {
        if(n==1 or k==1) return 1;
        n = min(n,k); this->n = n;
        dp.resize(n, vector<int>(k+1, -1));
        mp.clear(); return rec(0,k);
    }
};