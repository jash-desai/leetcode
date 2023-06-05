class Solution {
public:
    int findTheCity(int n, vector<vector<int>>&v, int k) {
        vector<vector<int>> dis(n, vector<int>(n,INT_MAX));
        for(auto x:v){
            dis[x[0]][x[1]] = x[2];
            dis[x[1]][x[0]] = x[2];
        }
        for(int i=0; i<n; i++) dis[i][i]=0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dis[i][k]==INT_MAX or dis[k][j]==INT_MAX) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        int a=-1; int c=n;
        for(int i=0; i<n; i++){
            int cc = 0;
            for(int j=0; j<n; j++){
                if(dis[i][j]<=k and i!=j) cc++;
            }
            if(cc<=c){
                c=cc;
                a=i;
            }
        }
        return a;
    }
};