class Solution {
public:
    int searchInsert(vector<int>&v, int k) {
        int l=0, r=v.size()-1; int m;
        while(l<=r){
            m = (l+r)/2;
            if(v[m]==k) return m;
            if(v[m]<k) l=m+1;
            else r=m-1;
        }
        return l;
    }
};