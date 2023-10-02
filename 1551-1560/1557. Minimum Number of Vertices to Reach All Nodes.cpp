class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& v) {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr); cin.tie(nullptr);
        unordered_set<int> s;
        for(const vector<int> &x : v) s.insert(x[1]);
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};