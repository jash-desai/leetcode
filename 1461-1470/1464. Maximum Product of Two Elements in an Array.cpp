class Solution {
public:
    int maxProduct(vector<int>& v) {
        sort(begin(v), end(v)); int n = v.size();
        int ans1 = (v[0]-1)*(v[1]-1);
        int ans2 = (v[n-1]-1)*(v[n-2]-1);
        return max(ans1, ans2);
    }
};