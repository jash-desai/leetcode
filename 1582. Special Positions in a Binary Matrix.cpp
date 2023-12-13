class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 0) continue;
                else{
                    bool f = 1;
                    for(int ni=0; ni<n; ni++){
                        if(ni!=i and v[ni][j]){
                            f = 0; break;
                        }
                    }
                    for(int nj=0; nj<m; nj++){
                        if(nj!=j and v[i][nj]){
                            f = 0; break;
                        }
                    }
                    ans += f;
                }
            }
        }
        return ans;
    }
};