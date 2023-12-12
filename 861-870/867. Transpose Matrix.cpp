class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][i] = v[i][j];
            }
        }
        return ans;
    }
};