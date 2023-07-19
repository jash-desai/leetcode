class Solution {
public:
    int singleNonDuplicate(vector<int>&v){
        int n = size(v), l = 1, r = n-2, m;
        if(n==1) return v[0];
        if(v[0] != v[1]) return v[0];
        if(v[n-1] != v[n-2]) return v[n-1];
        while(l<=r){
            m = (l + ((r-l) >> 1));
            if(v[m]!=v[m-1] and v[m]!=v[m+1]) return v[m];
            if((m%2 and v[m]==v[m-1]) or (!(m%2) and v[m]==v[m+1])){
                l = m+1;
            }else r = m-1;
        }
        return -1;
    }
};