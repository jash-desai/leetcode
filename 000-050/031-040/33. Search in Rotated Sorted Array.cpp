class Solution {
public:
    int search(vector<int>& v, int k) {
        int n=v.size(); int l=0, r=n-1;
        while(l<=r){
            int m = (l+r) >> 1;
            if(v[m]==k) return m;
            if(v[l]<=v[m]){
                if(v[l]<=k and k<=v[m]) r=m-1;
                else l = m+1;
            }else{
                if(v[m]<=k and k<=v[r]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};