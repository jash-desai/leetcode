class Solution {
public:
    void chk(int i, int j, vector<vector<int>>&v, int prev, vector<vector<bool>>&lk){
        if(i<0 or j<0 or i>=v.size() or j>=v[0].size()) return;
        if(lk[i][j]) return;
        if(v[i][j] < prev) return;
        lk[i][j]=1;

        chk(i-1,j,v,v[i][j],lk);
        chk(i,j+1,v,v[i][j],lk);
        chk(i+1,j,v,v[i][j],lk);
        chk(i,j-1,v,v[i][j],lk);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n=v.size(); int m=v[0].size();
        vector<vector<bool>> la(n, vector<bool>(m, 0));
        vector<vector<bool>> lb(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            chk(i,0,v,INT_MIN,la);
            chk(i,m-1,v,INT_MIN,lb);
        }
        for(int j=0; j<m; j++){
            chk(0,j,v,INT_MIN,la);
            chk(n-1,j,v,INT_MIN,lb);
        }
        vector<vector<int>> a;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(la[i][j] and lb[i][j]){
                    a.push_back({i,j});
                }
            }
        }
        return a;
        }
};