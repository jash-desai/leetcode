// class Solution {
//     unordered_map<string, int> mp; int n;
//     vector<int> cost, time;
// private:
//     int rec(int i, int k){
//         if(k<=0) return 0;
//         if(i==n) return 1e9;
//         string key = to_string(i) + ":" + to_string(k);
//         if(mp.count(key)) return mp[key];
//         int ans1 = rec(i+1, k);
//         int ans2 = cost[i] + rec(i+1, k - 1 - time[i]);
//         return mp[key] = min(ans1, ans2);
//     }
// public:
//     int paintWalls(vector<int>& cost, vector<int>& time) {
//         n = size(cost); mp.clear();
//         this->cost = cost; this->time = time;
//         return rec(0,n);
//     }
// };
class Solution {
    vector<vector<int>> dp; int n;
    vector<int> cost, time;
private:
    int rec(int i, int k) { 
        if(k <= 0) return 0;
        if(i == n) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];
        
        int a = cost[i] + rec(i + 1, k - 1 - time[i]);
        int b = rec(i + 1, k);
        return dp[i][k] = min(a, b);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size(); this->cost = cost; this->time = time;
        dp.assign(n, vector(n + 1, -1));
        return rec(0, n);
    }
};
