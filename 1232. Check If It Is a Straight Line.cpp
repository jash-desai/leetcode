class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v){
        int n=v.size();
        if(n<3) return true;
        long double m = v[1][1]-v[0][1];
        if((v[1][0]-v[0][0])==0){
            for(int i=2; i<n; i++){
                if(v[i][0] != v[1][0]){
                    return false;
                }
            }
            return true;
        }else{
            m = m/(v[1][0]-v[0][0]);
            long double c = v[0][1] - (m*v[0][0]);
            for(int i=2; i<n; i++){
                if(v[i][1]!=(v[i][0]*m + c)){
                    return false;
                }
            }
            return true;
        }
    }
};