class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int n=v.size();
        for(int i=2; i<n; i++){
            v[i] += min(v[i-1],v[i-2]);
        }
        return min(v[n-1], v[n-2]);
    }
};