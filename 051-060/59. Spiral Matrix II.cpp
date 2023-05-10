class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // if(n==0) return {};
        vector<vector<int>> v(n, vector<int>(n,0));
        int k = 1;
        int i=0; int j=0;
        int t;
        for(int q=n; q>1; q-=2){
            t=q;
            while(t--){
                v[i][j] = k++;
                j++;
            }
            j--; t=q-1; i++;
            while(t--){
                v[i][j] = k++;
                i++;
            }
            i--; t=q-1; j--;
            while(t--){
                v[i][j] = k++;
                j--;
            }
            j++; t=q-2; i--;
            while(t--){
                v[i][j] = k++;
                i--;
            }
            i++; j++;
        }
        if(n%2) v[i][j] = k;
        return v;
    }
};
