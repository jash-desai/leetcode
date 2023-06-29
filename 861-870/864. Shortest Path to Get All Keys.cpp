/*
#define pip pair<int, pair<int,int>>
#define pii pair<int,int>
class Solution {
private:
    int movable(vector<string>&v, int i, int j, set<char>&keys){
        // 0 - canot move // 1 - can move
        // 2 can move and collect key
        char c = v[i][j];
        if(c=='#') return 0;
        if(c=='.') return 1;
        if(c>='A' and c<='Z'){
            char sc = v[i][j] + 32;
            if(keys.find(sc) != keys.end()) return 1;
            else return 0;
        }
        if(c>='a' and c<='z') return 2;
        return 1;
    }
public:
    int shortestPathAllKeys(vector<string>&v) {
        int n = v.size(), m = v[0].size(), sr = -1, sc = -1;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int dr[] = {-1,0,1,0}; int dc[] = {0,1,0,-1};
        int keyCount = 0; queue<pip> q; set<char> keys;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char c = v[i][j];
                if(c>='a' and c<='z') keyCount++;
                if(c=='@'){
                    sr = i; sc = j;
                }
            }
        }
        q.push({0, {sr, sc}}); int ans = INT_MAX;
        while(!q.empty()){
            auto [r, c] = q.front().second;
            int d = q.front().first; q.pop();
            vis[r][c]=1;
            if(keys.size()==keyCount) ans = min(ans, d);
            for(int i=0; i<4; i++){
                int nr = r + dr[i], nc = dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    if(!vis[nr][nc]){
                        int id = movable(v,nr,nc,keys);
                        if(id==1){
                            q.push({d+1, {nr,nc}});
                        }
                        if(id==2){
                            keys.insert(v[nr][nc]);
                            q.push({d+1, {nr,nc}});
                        }
                    }
                }
            }
        }
        return (ans==INT_MAX)? -1 : ans;
    }
};
*/
class Solution {
public:
    int shortestPathAllKeys(vector<string>& v) {
        int m=v.size(), n=m?v[0].size():0;
        if(!m || !n) return 0;
        int path=0, K=0;
        vector<int> dirs={0,-1,0,1,0};
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(64,0)));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='@'){
                    q.push({i*n+j,0});
                    vis[i][j][0]=1;                    
                }
                if(v[i][j]>='A' && v[i][j]<='F') K++; 
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int a=q.front().first/n, b=q.front().first%n;
                int carry=q.front().second;
                q.pop();        
                if(carry==((1<<K)-1)) return path;
                for(int j=0;j<4;j++){
                    int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                    if(x<0 || x>=m || y<0 || y>=n || v[x][y]=='#') continue;
                    if(v[x][y]>='a' && v[x][y]<='f'){
                        k = carry | (1<<(v[x][y]-'a'));
                    }
                    else if(v[x][y]>='A' && v[x][y]<='F'){
                        if(!(carry & (1<<(v[x][y]-'A')))) continue;
                    }
                    if(!vis[x][y][k]){
                        vis[x][y][k]=1;
                        q.push({x*n+y,k});
                   }                
                }
            }
            path++;
        }
        return -1;
    }
};