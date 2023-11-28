class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size(), ans = n+1;
        sort(begin(v), end(v));
        vector<int> uniq(v.begin(), unique(begin(v), end(v)));
        for(int i=0; i<uniq.size(); i++){
            int l = uniq[i], r = l + n-1;
            int idx = upper_bound(begin(uniq), end(uniq), r) - uniq.begin();
            ans = min(ans, n - idx + i);
        }
        return ans;
    }
};