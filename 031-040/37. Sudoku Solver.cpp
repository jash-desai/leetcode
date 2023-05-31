class Solution {
private:
    bool safe(vector<vector<char>>&v, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(v[i][col] == c or v[row][i]==c){
                return false;
            }
            if(v[3*(row/3)+i/3][3*(col/3)+i%3] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& v) {
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                if(v[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){
                        if(safe(v, i, j, c)){
                            v[i][j] = c;
                            if(solve(v)) return true;
                            v[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>&v) {
        solve(v);
    }
};