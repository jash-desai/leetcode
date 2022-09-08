class Solution {
public:
    void setRow(int i, int j, vector<vector<int>>&v, vector<vector<bool>>&vis){
        // memset(v[i], 0, sizeof v[i]);
        for(int k=0; k<v[i].size(); k++){
            if(v[i][k]!=0){
                vis[i][k]=1;
                v[i][k]=0;
            }
        }

    }
    void setCol(int i, int j, vector<vector<int>>&v, vector<vector<bool>>&vis){
        for(int k=0; k<v.size(); k++){
            if(v[k][j]!=0){
                v[k][j]=0;
                vis[k][j]=1;
            }
        }
    }
    void setZeroes(vector<vector<int>>&v){
        vector<vector<bool>> vis(v.size(), vector<bool>(v[0].size(), 0));
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                if(v[i][j]==0 and vis[i][j]==0){
                    setRow(i,j,v,vis);
                    setCol(i,j,v,vis);
                }else{
                    vis[i][j]=1;
                }
            }
        }
    }
};