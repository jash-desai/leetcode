class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int n = size(v), m = size(v[0]);
        for(int i=0; i<n; i++){
            int l{0}, r = m-1;
            while(l<=r){
                int mid = l + ((r-l) >> 1);
                int up = i > 0 ? v[i-1][mid] : -1;
                int rt = mid < m-1 ? v[i][mid+1]:-1;
                int dn = i < n-1 ? v[i+1][mid] : -1;
                int lt = mid > 0 ? v[i][mid-1] : -1;
                int maxCol = max(up,dn), maxRow = max(lt,rt);
                if(v[i][mid] >= max(maxCol, maxRow)) return {i, mid};
                int mxLt = max(lt, v[i][0]), mxRt = max(rt, v[i][m-1]);
                if(mxLt > mxRt) r = mid-1;
                else l = mid+1;
            }
        }
        return {};
    }
};