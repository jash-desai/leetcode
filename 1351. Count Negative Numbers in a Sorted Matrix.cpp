class Solution {
public:
    int countNegatives(vector<vector<int>>&v){
        int n = v.size(); int m = v[0].size();
        int i = 0; int j = m-1; int a = 0;
        while(i>=0 and i<n and j>= 0 and j<m){
            if(v[i][j] < 0){
                a += (n-i);
                j--;
            }else i++;
        }
        return a;
    }
};