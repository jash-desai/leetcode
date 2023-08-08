class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>&v, int x, int y, int p) {
			int n = v.size(), m = v[0].size(); 
			vector<vector<bool>> vis(n, vector<bool>(m, 0));
	    // vector<vector<int>> ans = v;
			 queue<pair<int, int>> q; q.push({x, y});
			int k = v[x][y]; vis[x][y] = 1; 
			int dr[4] = {-1,0,1,0}; int dc[4] = {0,1,0,-1}; v[x][y] = p;
	    while(!q.empty()){
	    	int r = q.front().first;
	    	int c = q.front().second; q.pop();
	    	for(int i=0; i<4; i++){
	    		int nr = r + dr[i]; int nc = c + dc[i];
	    		if(nr>=0 and nr<n and nc>=0 and nc<m){
	    			if(!vis[nr][nc] and v[nr][nc] == k){
	    				q.push({nr, nc}); vis[nr][nc] = 1;
	    				v[nr][nc] = p;
	    			}
	    		}
	    	}
	    }
	    return v;
    }
};