const int MAX_N = 100'001;
static int in[MAX_N], dp[MAX_N][26], ts;
static vector<int> nei[MAX_N];
static deque<int> top;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        memset(in, 0, sizeof(in[0]) * n);
        for (int i = 0; i < n; i++) nei[i].clear();
        for (auto& e : edges) {
            in[e[1]]++;
            nei[e[0]].push_back(e[1]);
        }
        
        top.clear();
        for (int i = 0; i < n; i++) {
            if (!in[i]) top.push_back(i);
        }
        ts = 0;
        memset(dp, 0, sizeof(dp[0]) * n);
        for (int i = 0; i < n; i++) dp[i][colors[i] - 'a'] = 1;
        while (top.size()){
            int i = top.front();
            top.pop_front();
            ts++;
            for(int j : nei[i]) {
                in[j]--;
                if (!in[j]) top.push_back(j);
                for (int c = 0; c < 26; c++){
                    int qq = dp[i][c] + (colors[j]-'a'== c);
                    dp[j][c] = max(dp[j][c], qq);
                }
            }
        }
        if (ts != n) return -1;        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int c = 0; c < 26; c++){
                ans = max(ans, dp[i][c]);
            }
        }
        return ans;
    }
};