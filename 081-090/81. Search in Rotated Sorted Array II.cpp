class Solution {
public:
    bool search(vector<int>& v, int k) {
        int n = size(v), l = 0, r = n-1, m;
        while(l<=r){
            m = l + ((r-l) >> 1);
            if(v[m]==k) return true;
            if(v[l] == v[m] and v[m]==v[r]){ l++, r--; continue;}
            if(v[l] <= v[m]){
                if(v[l] <= k and k < v[m]) r = m-1;
                else l = m+1;
            }else{
                if(v[m] < k and k <= v[r]) l = m+1;
                else r = m-1;
            }
        }
        return false;
    }
};