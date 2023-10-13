// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& v) {
//         int n=v.size();
//         for(int i=2; i<n; i++){
//             v[i] += min(v[i-1], v[i-2]);
//         }
//         return min(v[n-1], v[n-2]);
//     }
// };
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[0], cost[1]);

        int dp[cost.size()];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size()-1; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[cost.size()-2], cost[cost.size()-1]+dp[cost.size()-3]);
    }
};