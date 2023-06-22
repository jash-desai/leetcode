class Solution {
public:
    int maxProfit(vector<int>&v, int k) {
        int n = v.size();
        if(n<2) return 0; 
        int curr = -v[0]; int ans = 0;
        for(int i=1; i<n; i++){
            curr = max(curr, ans - v[i]);
            ans = max(ans, v[i] - k + curr);
        }
        return ans;
    }
};