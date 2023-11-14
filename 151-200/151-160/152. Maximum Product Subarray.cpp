class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int cmax = v[0];
        int cmin = v[0];
        int ans = v[0];
        for(int i = 1; i < n; i++){
            int temp = cmax;
            cmax = max({v[i], cmax * v[i], cmin * v[i]});
            cmin = min({v[i], temp * v[i], cmin * v[i]});
            ans = max(ans, cmax);
        }
        return ans;
    }
};