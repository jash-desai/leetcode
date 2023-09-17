class Solution {
public:
    int maximalSquare(vector<vector<char>>&v) {
        int n = v.size(), m = v[0].size(), ans = 0;
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        for(int j=0; j<m; j++) cnt[0][j] = (v[0][j]=='1'), ans = max(ans, cnt[0][j]);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]=='0') continue;
                if(i-1>=0 and j-1>=0) cnt[i][j] = min({cnt[i][j-1], cnt[i-1][j-1], cnt[i-1][j]});
                cnt[i][j]++; ans = max(ans, (int)pow(cnt[i][j], 2));
            }
        }
        return ans;
    }
};