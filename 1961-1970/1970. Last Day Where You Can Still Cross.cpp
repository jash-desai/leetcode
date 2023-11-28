class Solution {
public:
    bool isPossible(int n, int m, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<pair<int,int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0; i<t; i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(grid[0][i]==0){
                q.push({0,i});
                grid[0][i] = 1;
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int r = p.first, c = p.second;
            for (auto &d : directions) {
                int nr = r + d.first, nc = c + d.second;
                if(nr >= 0 and nc >= 0 and nr < n and nc < m){
                    if(!grid[nr][nc]){
                        grid[nr][nc] = 1;
                        if (nr == n-1) return true;
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