#define all(x) x.begin(), x.end()
class Solution {
public:
    int minMoves2(vector<int>&v) {
        int n = v.size(); sort(all(v));
        int k, ans = 0;
        if(n%2) k = v[(n-1)>>1];
        else k = ((v[(n>>1)-1] + v[n>>1]) >> 1);
        for(int i=0; i<n; i++) ans += abs(v[i]-k);
        return ans;
    }
};