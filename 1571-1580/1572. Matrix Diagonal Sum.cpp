class Solution {
public:
    int diagonalSum(vector<vector<int>>& v) {
        int n = v.size();
        int a = 0;
        for(int i=0; i<n; i++){
            a += v[i][i];
            if(i != n-i-1){
                a += v[i][n-i-1]; 
            }
        }
        return a;
    }
};