class Solution {
public:
    int equalPairs(vector<vector<int>>&v) {
        map<vector<int>, int> mp;
        int n = v.size(), ans = 0;
        for(vector<int> x : v) mp[x]++;
        for(int i=0; i<n; i++){
            vector<int> t(n);
            for(int j=0; j<n; j++){
                t[j] = (v[j][i]);
            }
            ans += mp[t];
        }
        return ans;
    }
};