class Solution {
public:
    bool isPossible(int m, int n, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
        vector<pair<int,int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < t; i++) {
            grid[cells[i][0]][cells[i][1]] = 1;
        }
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            if(grid[1][i] == 0) {
                q.push({1, i});
                grid[1][i] = 1;
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int r = p.first, c = p.second;
            for (auto d : directions) {
                int nr = r + d.first, nc = c + d.second;
                if(nr > 0 && nc > 0 && nr <= m && nc <= n){
                    if(!grid[nr][nc]){
                        grid[nr][nc] = 1;
                        if (nr == m) return true;
                        q.push({nr, nc});
                    } 
                }
            }
        }
        return false;
    }

    int latestDayToCross(int n, int m, vector<vector<int>>&cells) {
        int l = 0, r = (n*m), ans = 0;
        while (l < r-1) {
            int mid = l + ((r-l) >> 1);
            if (isPossible(n, m, mid, cells)) {
                l = mid;
                ans = mid;
            } else r = mid;
        }
        return ans;
    }
};