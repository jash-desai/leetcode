class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& v) {
        int n = v.size();
        sort(begin(v), end(v), [&](auto&a, auto&b){
            return (a[0]<b[0]);
        });
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, v[i][0] - v[i-1][0]);
        }
        return ans;
    }
};